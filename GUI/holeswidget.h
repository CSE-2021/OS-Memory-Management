#ifndef HOLESWIDGET_H
#define HOLESWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QComboBox>
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
    QPushButton* btnAddHole;
    QPushButton* btnDelHole;
    QTableWidget* memTable;
    QComboBox* allocatorBox;

private:
    friend class GUIController;
    QVBoxLayout* mainLayout;
    QHBoxLayout* btns1Layout;

    QFormLayout* formLayout;
    QLabel* memSizeLbl;
    QLineEdit* memSizeEdit;

    QHeaderView* tableHeader;

void guiInit();
void setObjectNames();
void draw();
};

#endif // HOLESWIDGET_H
