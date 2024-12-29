#pragma once

#include "MainWindow.g.h"

#include "MainWindowViewModel.h"

namespace winrt::CppWinui::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
    {
        int32_t m_myProperty{ 0 };

        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

			this->m_viewModel = winrt::make<CppWinui::implementation::MainWindowViewModel>();
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        CppWinui::MainWindowViewModel ViewModel();

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    private:
        CppWinui::MainWindowViewModel m_viewModel{ nullptr };
    };
}

namespace winrt::CppWinui::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
