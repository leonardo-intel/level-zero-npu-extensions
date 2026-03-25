/*
*
* Copyright (C) 2026 Intel Corporation
*
* SPDX-License-Identifier: MIT
*
*/
#ifndef _ZE_DEVICE_NPU_EXT_H
#define _ZE_DEVICE_NPU_EXT_H
#if defined(__cplusplus)
#pragma once
#endif

#ifndef ZE_DEVICE_NPU_EXT_NAME
#define ZE_DEVICE_NPU_EXT_NAME "ZE_extension_device_npu"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Supported Device NPU Extension versions
///
/// @details
///     - NPU device extension versions contain major and minor attributes, use
///       ::ZE_MAJOR_VERSION and ::ZE_MINOR_VERSION
typedef enum _ze_device_npu_ext_version_t
{
    ZE_DEVICE_NPU_EXT_VERSION_1_0 = ZE_MAKE_VERSION( 1, 0 ),               ///< version 1.0
    ZE_DEVICE_NPU_EXT_VERSION_CURRENT = ZE_DEVICE_NPU_EXT_VERSION_1_0,     ///< latest known version
    ZE_DEVICE_NPU_EXT_VERSION_FORCE_UINT32 = 0x7fffffff

} ze_device_npu_ext_version_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Defines structure types
typedef enum _ze_structure_type_device_npu_ext_t
{
    ZE_STRUCTURE_TYPE_RUNTIME_REQUIREMENTS_DESC = 0x1,              ///< ::ze_runtime_requirements_desc_t
    ZE_STRUCTURE_TYPE_DEVICE_NPU_EXT_FORCE_UINT32 = 0x7fffffff

} ze_structure_type_device_npu_ext_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Handle type discriminator for requirementsSrc
typedef enum _ze_handle_type_t
{
    ZE_HANDLE_TYPE_GRAPH = 0x1,                                     ///< requirementsSrc is a ze_graph_handle_t
    ZE_HANDLE_TYPE_MODULE = 0x2,                                    ///< requirementsSrc is a ze_module_handle_t
    ZE_HANDLE_TYPE_FORCE_UINT32 = 0x7fffffff

} ze_handle_type_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Runtime requirements descriptor
///
/// @details
///     - Used to query and validate runtime requirements for compiled models
///     - Query mode: set requirementsSrc to a valid handle, driver populates pKey and pValue
///     - Validate mode: set pValue to a requirements string, requirementsSrc = NULL
///     - Key-only mode: set both requirementsSrc and pValue to NULL, driver populates pKey
typedef struct _ze_runtime_requirements_desc_t
{
    ze_structure_type_device_npu_ext_t stype;                       ///< [in] type of this structure
    const void* pNext;                                              ///< [in][optional] must be null or a pointer to an extension-specific structure
    const char* pValue;                                             ///< [in,out][optional] null-terminated string that describes the requirements
    const char* pKey;                                               ///< [out] null-terminated string that uniquely identifies the requirements
    void* requirementsSrc;                                          ///< [in][optional] source of the requirements (e.g. graph or module handle)
    ze_handle_type_t handleType;                                    ///< [in][optional] type of the handle in requirementsSrc

} ze_runtime_requirements_desc_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Query or validate runtime requirements for a device
typedef ze_result_t (ZE_APICALL *ze_pfnDeviceRequirementsQuery_ext_t)(
    ze_device_handle_t hDevice,                                             ///< [in] handle of the device
    ze_runtime_requirements_desc_t* pRequirements                           ///< [in,out] pointer to requirements descriptor
    );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Table of Device NPU functions pointers
typedef struct _ze_device_npu_dditable_ext_t
{
    // version 1.0
    ze_pfnDeviceRequirementsQuery_ext_t         pfnRequirementsQuery;

} ze_device_npu_dditable_ext_t;

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _ZE_DEVICE_NPU_EXT_H
