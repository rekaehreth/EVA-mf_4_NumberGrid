#include "gridsizedialog.h"

GridSizeDialog::GridSizeDialog()
{
    verticalLayout = new QVBoxLayout();

    Label = new QLabel;
    Label->setText( "Select the desired size" );
    spinBox = new QSpinBox;
    okButton = new QPushButton;
    cancelButton = new QPushButton;

    verticalLayout->addWidget( Label );
    verticalLayout->addWidget( spinBox );
    verticalLayout->addWidget( okButton );
    verticalLayout->addWidget( cancelButton );

    connect( okButton, SIGNAL(clicked()), this, SLOT(accept() ) );
    connect( cancelButton, SIGNAL(clicked()), this, SLOT(reject() ) );
}
