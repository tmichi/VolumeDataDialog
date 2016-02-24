#ifndef __VOLUME_DATA_DIALOG_HPP__
#define __VOLUME_DATA_DIALOG_HPP__ 1
#include <QDialog>
class QComboBox;
class QSlider;
class QSpinBox;
class QDoubleSpinBox;
class QPushButton;

class VolumeDataDialog : public QDialog
{
	Q_OBJECT
private:
        // Voxel Type
	QComboBox* _comboBox1; 

	// Voxel Size
	QSpinBox* _spinBox1; // X
	QSpinBox* _spinBox2; // Y
	QSpinBox* _spinBox3; // Z
	
	QSlider* _slider1; // X
	QSlider* _slider2; // Y
	QSlider* _slider3; // Z
	
	QSpinBox* _spinBox4; // header

	QDoubleSpinBox* _doubleSpinBox1; // pX
	QDoubleSpinBox* _doubleSpinBox2; // pY
	QDoubleSpinBox* _doubleSpinBox3; // pZ
	QComboBox* _comboBox2; // Voxel Type
	
	QPushButton* _pushButton1; // OK
	QPushButton* _pushButton2; // cancel
	
public:
	VolumeDataDialog( QWidget* parent = 0 );

	int getVoxelType(void);
	void getVolumeSize( int &x, int &y, int &z);
	void getVoxelPitch( float &x, float &y, float &z);
	int getHeaderSize(void);

	/**
	 * @retval QDialog::Accepted Succeeded.
	 * @retval QDialog::Rejected failed.
	 */
        static int getInfo ( int& type, int & x, int & y, int & z, float & px,  float & py,  float & pz, int& header); 

			       
private slots:
	void slot_set_pitch(int index);	
};


#endif// __VOLUME_DATA_DIALOG_HPP__
