#pragma once

#include "MainWindowViewModel.g.h"
#include "winrt/Windows.UI.Xaml.Data.h"
#include "Common.h"

namespace winrt::CppWinui::implementation
{
    struct MainWindowViewModel : MainWindowViewModelT<MainWindowViewModel>
    {
        MainWindowViewModel() = default;

        NotifyChangedProperty(int32_t, MyProperty);
        
        Bindable
    };
}

FactoryDefinition(MainWindowViewModel);
