#include <iostream>
#include "simulation.hpp"

core_data::simulation_data* create_simulation_parameter (size_t S,double T,double k,size_t s,double t) {

    auto *Basic_parameter_ptr = new user_input::simulation_parameter(S,T,k);
    Basic_parameter_ptr->implace(s,t);
    auto *simulation = new core_data::simulation_data(Basic_parameter_ptr,k);
    delete Basic_parameter_ptr;
    return simulation;
}


class temporary_simulation_list {

    core_data::simulation_data* simulation_list[1];                     // will replace with my vector

public:
    temporary_simulation_list() = default;

    ~temporary_simulation_list() {for (size_t i = 0; i < 1; i++) delete simulation_list[i];}

    void add_simulation (core_data::simulation_data* S)  { simulation_list[0] = S; }

    void tempeture_adjust (size_t t) {
        simulation_list[t]->tick();
    }

    void display (size_t t) {

        simulation_list[t]->display_rod_tempatures();
    }

};


int main () {

// create and store simulation
temporary_simulation_list list;
list.add_simulation(create_simulation_parameter (10, 10,0.1,1,100));
// tick and change
list.display(0);
    std::cout << "\n";
list.tempeture_adjust(0);
// display tempatures
list.display(0);
    std::cout << "\n";
list.tempeture_adjust(0);
// display tempatures
list.display(0);
    std::cout << "\n";
list.tempeture_adjust(0);
// display tempatures
list.display(0);
    std::cout << "\n";
list.tempeture_adjust(0);
// display tempatures
list.display(0);
    std::cout << "\n";
}
