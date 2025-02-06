#pragma once

#include "client/clientwidget.h"

#include <QMainWindow>

class MainWindow final : public QMainWindow
{
public:
    MainWindow();
    MainWindow(const MainWindow&) = delete;
    MainWindow(MainWindow&&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    MainWindow& operator=(MainWindow&&) = delete;

private:
    ClientWidget* _clientWidget{ nullptr };
};
