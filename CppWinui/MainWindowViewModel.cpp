#include "pch.h"
#include "MainWindowViewModel.h"
#include "Common.h"
#include "winrt/Windows.UI.Xaml.Data.h"
#if __has_include("MainWindowViewModel.g.cpp")
#include "MainWindowViewModel.g.cpp"
#endif

namespace winrt::CppWinui::implementation
{
    int32_t MainWindowViewModel::MyProperty()
    {
		return m_myProperty;
    }

    void MainWindowViewModel::MyProperty(int32_t value)
    {
        if (m_myProperty != value) {
            m_myProperty = value; 
            RaisePropertyChanged(L"MyProperty");
        };
    }
}
