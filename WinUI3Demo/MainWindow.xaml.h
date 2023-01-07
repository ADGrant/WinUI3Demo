// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

class Freezer
{
	bool& m_frozen;

public:

	Freezer(bool& frozen) : m_frozen(frozen)
	{
		m_frozen = true;
	}

	~Freezer()
	{
		m_frozen = false;
	}
};


namespace winrt::WinUI3Demo::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
	{
		bool m_freezeC = false;
		bool m_freezeF = false;
		MainWindow();

		void txtCelsius_TextChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& e);
		void txtFahrenheit_TextChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& e);
	};
}

namespace winrt::WinUI3Demo::factory_implementation
{
	struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
	{
	};
}
