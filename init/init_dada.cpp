// SPDX-License-Identifier: Apache-2.0

#include <string.h>
#include <unistd.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>

#include "vendor_init.h"

using android::base::GetProperty;

void property_override(const char* prop, const char* value) {
    auto pi = (prop_info*)__system_property_find(prop);
    if (pi != nullptr) {
        __system_property_update(pi, value, strlen(value));
    } else {
        __system_property_add(prop, strlen(prop), value, strlen(value));
    }
}

void vendor_load_properties() {
    if (access("/system/bin/recovery", F_OK) == 0 ||
        GetProperty("ro.bootmode", "") == "charger") {
        return;
    }

    // Brand and manufacturer
    property_override("ro.product.brand", "Xiaomi");
    property_override("ro.product.manufacturer", "Xiaomi");

    // Xiaomi partition codename consistency
    property_override("ro.build.flavor", "missi-user");
    property_override("ro.build.product", "missi");

    // System
    property_override("ro.product.system.brand", "Xiaomi");
    property_override("ro.product.system.device", "missi");
    property_override("ro.product.system.model", "missi");
    property_override("ro.product.system.name", "missi");

    // System_ext (Qualcomm BSP)
    property_override("ro.product.system_ext.device", "missi");
    property_override("ro.product.system_ext.manufacturer", "QUALCOMM");
    property_override("ro.product.system_ext.model", "missi");
    property_override("ro.product.system_ext.name", "missi");

    // Vendor
    property_override("ro.product.vendor.device", "mivendor");
    property_override("ro.product.vendor.model", "Xiaomi for arm64");
    property_override("ro.product.vendor.name", "mivendor");
    property_override("ro.vendor.build.version.sdk", "35");
}
