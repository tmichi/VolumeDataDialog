#include <QtGui>
#include "VolumeDataDialog.hpp"
VolumeDataDialog::VolumeDataDialog( QWidget* parent )
{

        this->setModal( true );
        this->setFixedSize( 400, 500 );
        this->setContentsMargins ( 5,5,5,5 );
        QVBoxLayout *vBoxLayout1 = new QVBoxLayout;
        QGroupBox *groupBox1 = new QGroupBox ( tr ( "Voxel type" ) );
        QHBoxLayout *hBoxLayout1 = new QHBoxLayout;
        QLabel* label1 = new QLabel( tr( "Type : " ) );
        this->_comboBox1 = new QComboBox;
        this->_comboBox1->addItem( tr( "unsigned char" ) );
        this->_comboBox1->addItem( tr( "char" ) );
        this->_comboBox1->addItem( tr( "unsigned short" ) );
        this->_comboBox1->addItem( tr( "short" ) );
        this->_comboBox1->addItem( tr( "unsigned int" ) );
        this->_comboBox1->addItem( tr( "int" ) );
        this->_comboBox1->addItem( tr( "float" ) );
        this->_comboBox1->addItem( tr( "double" ) );
        hBoxLayout1->addWidget( label1 );
        hBoxLayout1->addWidget( this->_comboBox1 );
        hBoxLayout1->addStretch();
        groupBox1->setLayout ( hBoxLayout1 );

        const int minSize = 1;
        const int maxSize = 2048;

        QGroupBox* groupBox2 = new QGroupBox( tr( "Size" ) );
        QGridLayout *gridLayout1 = new QGridLayout;
        QLabel *label2 = new QLabel( tr( "X:" ) );
        this->_slider1  = new QSlider( Qt::Horizontal );
        this->_slider1->setRange( minSize, maxSize );
        this->_spinBox1 = new QSpinBox;
        this->_spinBox1->setRange( minSize, maxSize );
        QLabel *label3 = new QLabel( tr( "Y:" ) );
        this->_slider2  = new QSlider( Qt::Horizontal );
        this->_slider2->setRange( minSize, maxSize );
        this->_spinBox2 = new QSpinBox;
        this->_spinBox2->setRange( minSize, maxSize );
        QLabel *label4 = new QLabel( tr( "Z:" ) );
        this->_slider3  = new QSlider( Qt::Horizontal );
        this->_slider3->setRange( minSize, maxSize );
        this->_spinBox3 = new QSpinBox;
        this->_spinBox3->setRange( minSize, maxSize );
        connect( this->_slider1, SIGNAL( valueChanged( int ) ), this->_spinBox1, SLOT( setValue( int ) ) );
        connect( this->_spinBox1, SIGNAL( valueChanged( int ) ), this->_slider1, SLOT( setValue( int ) ) );
        connect( this->_slider2, SIGNAL( valueChanged( int ) ), this->_spinBox2, SLOT( setValue( int ) ) );
        connect( this->_spinBox2, SIGNAL( valueChanged( int ) ), this->_slider2, SLOT( setValue( int ) ) );
        connect( this->_slider3, SIGNAL( valueChanged( int ) ), this->_spinBox3, SLOT( setValue( int ) ) );
        connect( this->_spinBox3, SIGNAL( valueChanged( int ) ), this->_slider3, SLOT( setValue( int ) ) );
        this->_slider1->setValue( 512 );
        this->_slider2->setValue( 512 );
        this->_slider3->setValue( 512 );

        gridLayout1->addWidget( label2,0,0 );
        gridLayout1->addWidget( this->_slider1	,0,1 );
        gridLayout1->addWidget( this->_spinBox1	,0,2 );
        gridLayout1->addWidget( label3	,1,0 );
        gridLayout1->addWidget( this->_slider2,1,1 );
        gridLayout1->addWidget( this->_spinBox2,1,2 );
        gridLayout1->addWidget( label4,2,0 );
        gridLayout1->addWidget( this->_slider3,2,1 );
        gridLayout1->addWidget( this->_spinBox3,2,2 );
        groupBox2->setLayout ( gridLayout1 );

        QGroupBox *groupBox3 = new QGroupBox ( tr ( "Header size" ) );
        QHBoxLayout *hBoxLayout2 = new QHBoxLayout;
        this->_spinBox4 = new QSpinBox;
        this->_spinBox4->setMinimum( 0 );
        QLabel* label5 = new QLabel( tr( "Bytes" ) );
        hBoxLayout2->addStretch();
        hBoxLayout2->addWidget( this->_spinBox4 );
        hBoxLayout2->addWidget( label5 );
        groupBox3->setLayout ( hBoxLayout2 );

        QGroupBox *groupBox4 = new QGroupBox ( tr ( "Voxel pitch" ) );
        QVBoxLayout *vBoxLayout2 = new QVBoxLayout;
        QWidget *widget2 = new QWidget;
        QHBoxLayout *hBoxLayout3 = new QHBoxLayout;
        this->_doubleSpinBox1 = new QDoubleSpinBox;
        this->_doubleSpinBox1->setMinimum( 0.0001 );
        this->_doubleSpinBox1->setValue( 1 );
        this->_doubleSpinBox1->setDecimals( 5 );
        this->_doubleSpinBox2 = new QDoubleSpinBox;
        this->_doubleSpinBox2->setMinimum( 0.0001 );
        this->_doubleSpinBox2->setValue( 1 );
        this->_doubleSpinBox2->setDecimals( 5 );
        this->_doubleSpinBox3 = new QDoubleSpinBox;
        this->_doubleSpinBox3->setMinimum( 0.0001 );
        this->_doubleSpinBox3->setValue( 1 );
        this->_doubleSpinBox3->setDecimals( 5 );
        QLabel* label6 = new QLabel( tr( "x" ) );
        QLabel* label7 = new QLabel( tr( "x" ) );
        hBoxLayout3->addWidget( this->_doubleSpinBox1 );
        hBoxLayout3->addWidget( label6 );
        hBoxLayout3->addWidget( this->_doubleSpinBox2 );
        hBoxLayout3->addWidget( label7 );
        hBoxLayout3->addWidget( this->_doubleSpinBox3 );
        widget2->setLayout( hBoxLayout3 );
        this->_comboBox2 = new QComboBox;
        this->_comboBox2->addItem( tr( "Uniform grid (1 x 1 x 1)" ) );
        this->_comboBox2->addItem( tr( "Anistropic grid (0.4 x 0.4 x 0.5)" ) );
        connect( this->_comboBox2, SIGNAL( activated( int ) ), this, SLOT( slot_set_pitch( int ) ) );
        vBoxLayout2->addWidget( widget2 );
        vBoxLayout2->addWidget( this->_comboBox2 );
        groupBox4->setLayout ( vBoxLayout2 );

        QWidget *widget1 = new QWidget;
        QHBoxLayout *hBoxLayout4 = new QHBoxLayout;
        this->_pushButton1 = new QPushButton( tr( "OK" ) );
        this->_pushButton2 = new QPushButton( tr( "Cancel" ) );

        connect( this->_pushButton1, SIGNAL( clicked() ), this, SLOT( accept() ) );
        connect( this->_pushButton2, SIGNAL( clicked() ), this, SLOT( reject() ) );

        hBoxLayout4->addStretch();
        hBoxLayout4->addWidget( this->_pushButton1 );
        hBoxLayout4->addWidget( this->_pushButton2 );
        widget1->setLayout ( hBoxLayout4 );

        vBoxLayout1->addWidget( groupBox1 );
        vBoxLayout1->addWidget( groupBox2 );
        vBoxLayout1->addWidget( groupBox3 );
        vBoxLayout1->addWidget( groupBox4 );
        vBoxLayout1->addWidget( widget1 );
        this->setLayout( vBoxLayout1 );
        return;
}
void
VolumeDataDialog::slot_set_pitch( int index )
{

        float px = 1;
        float py = 1;
        float pz = 1;

        switch ( index ) {
        case 0 :
                px = 1;
                py = 1;
                pz = 1;
                break;
        case 1 :
                px = 0.4f;
                py = 0.4f;
                pz = 0.5f;
                break;
        default :
                break;
        }
        this->_doubleSpinBox1->setValue( px );
        this->_doubleSpinBox2->setValue( py );
        this->_doubleSpinBox3->setValue( pz );
        return;
}

int
VolumeDataDialog::getVoxelType( void )
{
        return this->_comboBox1->currentIndex();
}

void
VolumeDataDialog::getVolumeSize( int &x, int &y, int &z )
{
        x = this->_spinBox1->value();
        y = this->_spinBox2->value();
        z = this->_spinBox3->value();
        return;
}

void
VolumeDataDialog::getVoxelPitch( float &x, float &y, float &z )
{
        x = this->_doubleSpinBox1->value();
        y = this->_doubleSpinBox2->value();
        z = this->_doubleSpinBox3->value();
        return;
}

int
VolumeDataDialog::getHeaderSize( void )
{
        return this->_spinBox4->value();
}

int
VolumeDataDialog::getInfo ( int& type, int & x, int & y, int & z, float & px,  float & py,  float & pz, int& header )
{
        VolumeDataDialog dialog;
        dialog.show();
        int result = dialog.exec();
        if( result == QDialog::Accepted ) {
                type = dialog.getVoxelType();
                dialog.getVolumeSize( x, y, z );
                dialog.getVoxelPitch( px,py,pz );
                header = dialog.getHeaderSize();
        } else {
                type = -1;
                x = 0;
                y = 0;
                z = 0;
                px = 0;
                py = 0;
                pz = 0;
                header = 0;
        }
        return result;
}
