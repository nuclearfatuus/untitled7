#include <iostream>
#include <vector>

class isotope {
    double A;
    double Z;
    std::string isotope_name;

public:

    void print() const{
        std::cout <<A<< ' ' << Z<< ' ' << isotope_name << std::endl;
    }


    isotope (double _A, double _Z, std::string _name) {
        if (_A > 0.0 && _Z > 0.0) {
            if (_Z < _A) {
                A = _A;
                Z = _Z;
                isotope_name = _name;
                std::cout << A << ' ' << Z << ' ' << isotope_name << std::endl;
            }
            else
                std::cout << "Z>A - wrong parameters, try again" << std::endl;

        } else
            std::cout << "wrong parameters, try again" << std::endl;
    }
    };

class element {
    std::vector<isotope> IoF;
    int number_of_isotopes;
    std::string element_name;
    std::vector<double>FM;
    double SoE;

public:

    void print() const{
        std::cout << '"';
        for(auto&item:IoF){
            item.print();
        }
        std::cout << ' ' << number_of_isotopes << ' ' << element_name  <<std::endl;
        std::cout << '"' <<std::endl;
    }


    element(int number_of_isotopes, const std::string element_name) : number_of_isotopes(number_of_isotopes), element_name(element_name) {
        std::cout<<number_of_isotopes<<' '<<element_name<<std::endl;

    }

    void AddIsotope(isotope* iso, double fm){
        double sum=0;

        FM.push_back(fm);
        IoF.push_back(*iso);

        for(int i=0; i<IoF.size(); i++) {
            sum += FM.at(i);
        }

        if (sum<=1.0) {
            for(auto&item:IoF)
                item.print();
            }
            else
                std::cout<<"error"<<std::endl;
        }
};

class material {
    std::string name;
    double density;
    std::vector<element> MoE;
    std::vector<double>FM;

public:

    material(const std::string name, double density) : name(name), density(density) {
        std::cout<< name << ' '<< density<< std::endl;
    }

    void AddElement(element* el, double fm){
        double sum=0;

        FM.push_back(fm);
        MoE.push_back(*el);

        for(int i=0; i<MoE.size(); i++) {
            sum += FM.at(i);
        }

        if (sum<=1.0) {
            for(auto&item:MoE)
                item.print();
        }
        else
            std::cout<<"error"<<std::endl;
    }
};


int main() {

isotope C12(12.0,6.0,"carbon12");
isotope C13(13.0, 6.0, "carbon13");

element C(2, "carbon");
C.AddIsotope(&C12, 0.9893);
C.AddIsotope(&C13, 0.107);

material GRAPHITE("graphite", 2.08);
GRAPHITE.AddElement(&C, 1.00);

isotope Si28(28.0, 14.0, "silicon28");
isotope Si29(29.0, 14.0, "silicon29");
isotope Si30(30.0, 14.0, "silicon30");

element Si(3, "silicon");
Si.AddIsotope(&Si28, 0.09223);
Si.AddIsotope(&Si29, 0.467);
Si.AddIsotope(&Si30, 0.310);

isotope O16(16.0, 8.0, "oxygen16");
isotope O17(17.0, 8.0, "oxygen17");
isotope O18(18.0, 8.0, "oxygen18");

element O(3, "oxygen");
O.AddIsotope(&O16, 0.99759);
O.AddIsotope(&O17, 0.0037);
O.AddIsotope(&O18, 0.0204);

material SiO2("Silicon dioxide", 2.648);
SiO2.AddElement(&Si, 0.3);
SiO2.AddElement(&O, 0.6);




    return 0;
}