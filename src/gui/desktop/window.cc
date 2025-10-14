#include "window.h"


MyWindow::MyWindow(QWidget *parent) : QWidget(parent)
{
    // Создаем элементы интерфейса
    QLabel *label = new QLabel("Добро пожаловать в Qt приложение!", this);

    
    // Создаем layout и добавляем элементы
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);

    
    
    // Настройки окн
    setWindowTitle("Мое первое Qt приложение");
    resize(300, 150);
}
