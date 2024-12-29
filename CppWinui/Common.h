#pragma once

#define Bindable \
public:\
event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)\
{\
    return m_propertyChanged.add(value);\
}\
void PropertyChanged(event_token const& token)\
{\
    m_propertyChanged.remove(token);\
}\
private:\
event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;\
void RaisePropertyChanged(hstring const& propertyName)\
{\
    m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));\
}

#define UpdateValue(propertyName, var, value) \
if (var != value)\
{\
    var = value;\
    RaisePropertyChanged(propertyName);\
}