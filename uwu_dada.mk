#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit_only.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common Lineage stuff.
UWU_DEVICE_TYPE := phone
UWU_SUPPORTS_TELEPHONY := true
UWU_MAINTAINER := Mairen
UWU_BUILDTYPE := RELEASE
$(call inherit-product, vendor/uwu/config/common.mk)

# Inherit from dada device
$(call inherit-product, device/xiaomi/dada/device.mk)

PRODUCT_NAME := uwu_dada
PRODUCT_DEVICE := dada
PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := 24129PN74C

PRODUCT_SYSTEM_NAME := dada
PRODUCT_SYSTEM_DEVICE := dada

PRODUCT_BUILD_PROP_OVERRIDES += \
    BuildDesc="dada-user 15 AQ3A.250226.002 OS3.0.305.0.WOCEUXM release-keys" \
    BuildFingerprint=Xiaomi/dada/dada:15/AQ3A.250226.002/OS3.0.305.0.WOCEUXM:user/release-keys \
    DeviceName=$(PRODUCT_SYSTEM_DEVICE) \
    DeviceProduct=$(PRODUCT_SYSTEM_NAME)

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi
