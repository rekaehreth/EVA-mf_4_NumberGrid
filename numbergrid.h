#ifndef NUMBERGRID_H
#define NUMBERGRID_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

class NumberGrid : public QWidget
{
    Q_OBJECT

private:
    QLCDNumber* _lcdNumber;
    QGridLayout* _gridLayout;
    QVBoxLayout* _vBoxLayout;
public:
    NumberGrid(QWidget *parent = nullptr);
    ~NumberGrid();

private slots:
    void setNumber();
};
#endif // NUMBERGRID_H
