// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Demo::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    void MainWindow::txtCelsius_TextChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& e)
    {
        winrt::hstring text = txtCelsius().Text();
        if (!text.empty() && text != L"-")
        {
            try
            {
                double celsius = std::stod(text.c_str());
                double fahrenheit = 32 + 1.8 * celsius;
                txtFahrenheit().Text(std::to_wstring(fahrenheit));
            }
            catch (...)
            {
                txtFahrenheit().Text(L"");
            }
        }
        else
        {
            txtFahrenheit().Text(L"");
        }
    }

    void MainWindow::txtFahrenheit_TextChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& e)
    {
        winrt::hstring text = txtFahrenheit().Text();
        if (!text.empty() && text != L"-")
        {
            try
            {
                double fahrenheit = std::stod(text.c_str());
                double celsius = (fahrenheit - 32) / 1.8;
                txtCelsius().Text(std::to_wstring(celsius));
            }
            catch (...)
            {
                txtCelsius().Text(L"");
            }
        }
        else
        {
            txtCelsius().Text(L"");
        }
    }
}
