#ifndef HOLESWIDGET_H
#define HOLESWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
class HolesWidget :public QGroupBox
{
    Q_OBJECT

public:
    HolesWidget(QWidget *parent = nullptr);
    QPushButton* btnNext;
private:
    friend class GUIController;
    QVBoxLayout* mainLayout;
    QHBoxLayout* btns1Layout;
    QPushButton* btnAddHole;
    QPushButton* btnDelHole;

    QFormLayout* formLayout;
    QLabel* memSizeLbl;
    QLineEdit* memSizeEdit;
    QTableWidget* memTable;
    QHeaderView* tableHeader;

};

#endif // HOLESWIDGET_H
