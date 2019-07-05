﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "pch.h"
#include "common.h"

#include "NumberBox.g.h"
#include "NumberBox.properties.h"

#define DEFAULTVALUE 0.0

enum NumberBoxSpinButtonPlacementMode
{
    Hidden,
    Inline
};

enum NumberBoxBasicValidationMode
{
    InvalidInputOverwritten,
    IconMessage,
    TextBlockMessage,
    Disabled
};

// Temporarily renamed "None" to Disabled because of previous definition issue
enum NumberBoxMinMaxMode
{
    BoundsDisabled,
    MinEnabled,
    MaxEnabled,
    MinAndMaxEnabled,
    WrapEnabled
};

enum NumberBoxNumberRounder
{
    RounderDisabled,
    IncrementNumberRounder,
    SignificantDigitsNumberRounder
};


class NumberBox :
    public ReferenceTracker<NumberBox, winrt::implementation::NumberBoxT>,
    public NumberBoxProperties
{

public:
    NumberBox();
    ~NumberBox() {}

    // IFrameworkElement
    void OnApplyTemplate();

    void OnPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);




private:

    void OnTextBoxGotFocus(winrt::IInspectable const& sender, winrt::RoutedEventArgs const& args);
    void OnTextBoxLostFocus(winrt::IInspectable const& sender, winrt::RoutedEventArgs const& args);
    void UpdateTextToValue();

    winrt::TextBox m_TextBox{ nullptr };

};
