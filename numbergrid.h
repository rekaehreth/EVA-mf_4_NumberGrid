#ifndef NUMBERGRID_H
#define NUMBERGRID_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "gridsizedialog.h"
#include <QVector>

class NumberGrid : public QWidget
{
    Q_OBJECT

private:
    QLCDNumber* _lcdNumber;
    QPushButton* _sizeButton;
    QGridLayout* _gridLayout;
    QVBoxLayout* _vBoxLayout;
    GridSizeDialog* _gridSizeDialog;
    QVector<QPushButton* > _buttonGrid;

public:
    NumberGrid(QWidget *parent = nullptr);
    ~NumberGrid();

private slots:
    void setNumber();
    void resizeGrid();
};
#endif // NUMBERGRID_H
