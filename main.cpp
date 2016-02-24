#include <QApplication>
#include "VolumeDataDialog.hpp"
#include <fstream>
int main( int argc, char *argv[] )
{
        QApplication app( argc, argv );

        int type, x,y,z, header;
        float px, py, pz;
        std::ofstream fout( "out.txt" );
        if( VolumeDataDialog::getInfo( type, x, y, z, px, py, pz, header ) == QDialog::Accepted ) {
                fout<<"type"<<type<<std::endl;;
                fout<<"Size:"<<x<<" "<<y<<" "<<z<<std::endl;
                fout<<"Pitch:"<<px<<" "<<py<<" "<<pz<<std::endl;
                fout<<"Header: "<<header<<std::endl;
        } else {
                // do nothing, if rejected.
        }

        return 1;
}
