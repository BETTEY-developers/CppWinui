#pragma once

#include "MainWindowViewModel.g.h"
#include "winrt/Windows.UI.Xaml.Data.h"
#include "Common.h"

namespace winrt::CppWinui::implementation
{
    struct MainWindowViewModel : MainWindowViewModelT<MainWindowViewModel>
    {
        MainWindowViewModel() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    private:
		int32_t m_myProperty{ 0 };
    public:
        event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value) {
            return m_propertyChanged.add(value);
        }
        void PropertyChanged(event_token const& token) {
            m_propertyChanged.remove(token);
        }
    private:
        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged; 
        void RaisePropertyChanged(hstring const& propertyName) {
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
        }
    };
}

namespace winrt::CppWinui::factory_implementation
{
    struct MainWindowViewModel : MainWindowViewModelT<MainWindowViewModel, implementation::MainWindowViewModel>
    {
    };
}
