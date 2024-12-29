#pragma once

#include "MainWindow.g.h"

#include "MainWindowViewModel.h"

namespace winrt::CppWinui::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

            SetPropertyValue(ViewModel, winrt::make<CppWinui::implementation::MainWindowViewModel>());
        }
        
		ReadonlyProperty(CppWinui::MainWindowViewModel, ViewModel);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

FactoryDefinition(MainWindow);
