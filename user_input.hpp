#include <iostream>

namespace user_input {

struct simulation_parameter_interface {

    virtual  size_t  acess_size()  const = 0;
    virtual  double  acess_tempature()  const = 0;
    virtual ~simulation_parameter_interface();
};

struct Basic_parameter : public simulation_parameter_interface {

    size_t m_size;
    double Tempeture;

public:

    Basic_parameter() = default;

    Basic_parameter (size_t S, double T)  { m_size = S; Tempeture = T; }

    size_t acess_size ()  const {return m_size;}
    double acess_tempature ()  const {return Tempeture;}
};


}; // end of namespace