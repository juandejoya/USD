//
// Copyright 2022 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* ** This file is generated by a script.  Do not edit directly.  Edit     ** */
/* ** defs.py or the (*)Schema.template.cpp files to make changes.         ** */
/* ************************************************************************** */

#include "pxr/imaging/hd/selectionSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"


PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdSelectionSchemaTokens,
    HDSELECTION_SCHEMA_TOKENS);



HdBoolDataSourceHandle
HdSelectionSchema::GetFullySelected()
{
    return _GetTypedDataSource<HdBoolDataSource>(
        HdSelectionSchemaTokens->fullySelected);
}

/*static*/
HdContainerDataSourceHandle
HdSelectionSchema::BuildRetained(
        const HdBoolDataSourceHandle &fullySelected
)
{
    TfToken names[1];
    HdDataSourceBaseHandle values[1];

    size_t count = 0;
    if (fullySelected) {
        names[count] = HdSelectionSchemaTokens->fullySelected;
        values[count++] = fullySelected;
    }

    return HdRetainedContainerDataSource::New(count, names, values);
}


HdSelectionSchema::Builder &
HdSelectionSchema::Builder::SetFullySelected(
    const HdBoolDataSourceHandle &fullySelected)
{
    _fullySelected = fullySelected;
    return *this;
}

HdContainerDataSourceHandle
HdSelectionSchema::Builder::Build()
{
    return HdSelectionSchema::BuildRetained(
        _fullySelected
    );
}


PXR_NAMESPACE_CLOSE_SCOPE