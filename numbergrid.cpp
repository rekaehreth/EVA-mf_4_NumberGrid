#include "numbergrid.h"

NumberGrid::NumberGrid(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle( tr( "Number Grid" ) ); // translate
    setFixedSize( 400, 400 );
    _lcdNumber = new QLCDNumber();
    _gridLayout = new QGridLayout();
    _vBoxLayout = new QVBoxLayout();

    for ( int i = 0; i < 10; ++i ) {
        for ( int j = 0; j < 10; ++j ) {
            QPushButton* button=new QPushButton( QString::number( i*10+j+1 ),this );
            _gridLayout->addWidget( button, i, j );
            QObject::connect( button, SIGNAL(clicked()), this, SLOT( setNumber() ) );
        }
    }

    _vBoxLayout->addWidget(_lcdNumber);
    _vBoxLayout->addLayout(_gridLayout);
    setLayout(_vBoxLayout);
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

