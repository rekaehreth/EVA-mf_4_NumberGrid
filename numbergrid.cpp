#include "numbergrid.h"

void NumberGrid::resizeGrid()
{
    foreach( QPushButton* button, _buttonGrid )
    {
        _gridLayout->removeWidget(button);
        delete button;
    }
    _buttonGrid.clear();

    for ( int i = 0; i < _gridSizeDialog->gridSize(); ++i ) {
        for ( int j = 0; j < _gridSizeDialog->gridSize(); ++j ) {
            QPushButton* button = new QPushButton( QString::number( i * _gridSizeDialog->gridSize() + j + 1 ), this );
            _buttonGrid.push_back( button );
            _gridLayout->addWidget( button, i, j );
            QObject::connect( button, SIGNAL(clicked()), this, SLOT( setNumber() ) );
        }
    }
    _vBoxLayout->addLayout( _gridLayout );
    setLayout( _vBoxLayout );
}

NumberGrid::NumberGrid(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle( tr( "Number Grid" ) ); // translate
    setFixedSize( 400, 400 );
    _lcdNumber = new QLCDNumber();
    _gridLayout = new QGridLayout();
    _vBoxLayout = new QVBoxLayout();
    _sizeButton = new QPushButton();
    _gridSizeDialog = new GridSizeDialog();
    _vBoxLayout->addWidget( _sizeButton );
    _vBoxLayout->addWidget( _lcdNumber );
    resizeGrid();


    connect( _sizeButton, SIGNAL(clicked()), _gridSizeDialog, SLOT(exec() ) );
    connect( _gridSizeDialog, SIGNAL(accepted()), this, SLOT(resizeGrid() ) );
}

NumberGrid::~NumberGrid()
{
}

void NumberGrid::setNumber()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if ( senderButton->text() != "X" ) {
        _lcdNumber->display( senderButton->text() );
        senderButton->setText( "X" );
    }
}

