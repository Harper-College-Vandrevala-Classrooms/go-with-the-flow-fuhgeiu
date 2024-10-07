#include <iostream>

namespace user_input {



struct simulation_parameter {
private:
    size_t m_size;
    double Tempeture,K;
    double* m_data = nullptr;

public:

    simulation_parameter() = default;

    ~simulation_parameter()  { delete[] m_data; m_data = nullptr; }

    simulation_parameter (size_t S, double T,double k)  {

        m_data = new double[S];
        m_size = S;
        Tempeture = T; K = k;
        for (size_t i = 0; i < S; i++) { m_data[i] = T; }
    }

    void implace (size_t s, double T) {

        if (m_data == nullptr) std::cout << "cannot assign when container does not exist\n";
            else {m_data [s-1] = T;}
    }

    size_t acess_size ()  const {return m_size;}
    double* acess_data () const {return m_data;}
    double acess_K () const {return K;}
};


}; // end of namespace


namespace core_data {


class simulation_data {

    double* m_data = nullptr;
    size_t m_length = 0;
    double K;

public:

    simulation_data () = default;

    simulation_data (const user_input::simulation_parameter* parameter,double k) {

        m_length = parameter->acess_size();
        K = parameter->acess_K();
        m_data = new double[m_length];
        memcpy(m_data,parameter->acess_data(),sizeof(*m_data)*m_length);
    }

// tick to change tempatures
    void tick () {

        for (size_t i = 0; i < m_length; i++) {

            m_data[i] = (m_data[i] + K*(m_data[(i+1) % m_length] -2*(m_data[i]) + m_data[(i-1) % m_length]));
        }
    }


    void display_rod_tempatures () {

        for (size_t i = 0; i < m_length; i++) { std::cout << " | " << m_data[i]; if (i == 9) std::cout << " | "; }
    }

};  // end of class


}   // end of namespace