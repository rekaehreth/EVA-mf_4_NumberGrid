#ifndef NUMBERGRIDWIDGET_H
#define NUMBERGRIDWIDGET_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>

class GridSizeDialog : public QDialog
{
private:
    QLabel* Label;
    QSpinBox* spinBox;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QVBoxLayout* verticalLayout;
public:
    GridSizeDialog();
    int gridSize();
};

#endif // NUMBERGRIDWIDGET_H
