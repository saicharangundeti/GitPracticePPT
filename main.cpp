#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Control
{
    int id;
    string type;
    string state;

    void details()
    {
        cout << "Id->" << id << ", Type->"<< type <<", State->"<< state <<endl;
    }
};

class ControlsSystem
{

    vector<Control> controls;

public:
    // builds all the controls
    void buildControls()
    {
        Control c1 = {1,"button","visible"};
        Control c2 = {2,"slider","visible"};
        Control c3 = {3,"button","disable"};
        Control c4 = {4,"slider","visible"};
        Control c5 = {5,"slider","invisible"};
        Control c6 = {6,"button","visible"};
        Control c7 = {7,"slider","invisible"};
        Control c8 = {8,"button","disable"};
        Control c9 = {9,"slider","disable"};
        Control c10 = {10,"button","invisible"};

        controls.push_back(c1);
        controls.push_back(c2);
        controls.push_back(c3);
        controls.push_back(c4);
        controls.push_back(c5);
        controls.push_back(c6);
        controls.push_back(c7);
        controls.push_back(c8);
        controls.push_back(c9);
        controls.push_back(c10);
       // cout << c1.details() << endl;

    }
    // prints all the controls in the system
    void getAllControls()
    {
        cout << "Controllers are : " << endl;
        for(Control control : controls)
        {
            control.details();
        }
    }
    // gets the details of given id
    void getDetailsForId(int id)
    {
        auto targetContorl = find_if(controls.begin(),controls.end(),
                                     [id](Control &c){return c.id == id;});
        if(targetContorl != controls.end())
        {
            cout << "Id " << id << " control details are: " << "Type->"<<targetContorl->type << ", State->"<< targetContorl->state << endl;
            // targetContorl->details();

            // cout << endl;
        }
        else
        {
            cout << "Id " << id <<  " not found in controls " << endl;
        }
    }

    // finds the first invisible control
    void getFirstInvisibleControl()
    {
        auto firstInvisibleControl = find_if(controls.begin(),controls.end(),
                                           [](Control &c){return c.state == "invisible";});
        if(firstInvisibleControl != controls.end())
        {
            cout << "First invisible control details are :";
            firstInvisibleControl->details();
        }
        else
        {
            cout << "no invisible control present " << endl;
        }
    }
     // gets the details of given id
    void findIfAdjacentStateAreEqual()
    {
        auto adjacentStates = adjacent_find(controls.begin(),controls.end(),
                                            [](Control &c1, Control &c2) {return c1.state == c2.state; });
        if(adjacentStates != controls.end())
        {
            cout << "First adjacent pair with same state are :"<<endl;
            adjacentStates->details();
            (adjacentStates+1)->details();
        }
        else
        {
            cout <<"No adjacent cotrols with same state"<<endl;
        }
    }
    int countVisibleControls()
    {
        auto countVisibles = count_if(controls.begin(),controls.end(),[](Control& c){return c.state == "visible";});
        return countVisibles;

    }
    int countDisabledSliders()
    {
        auto disabledSliders = count_if(controls.begin(),controls.end(),[](Control &c){return c.type=="slider" && c.state == "disable"; });
        return disabledSliders;
    }

};

int main()
{


    ControlsSystem c;
    c.buildControls(); // builds all the controls

    c.getAllControls(); // prints all the controls

    c.getFirstInvisibleControl(); // finds the fisrt occurence of invisible control

    c.getDetailsForId(7); // gets the details of given id

    c.getDetailsForId(20); // if id not present

    c.findIfAdjacentStateAreEqual();// find the details of two adjecent controls which are equal state

    cout << "count of visible Controls :"<< c.countVisibleControls() << endl;

    cout << "count of disabled sliders :"<< c.countDisabledSliders() << endl;


    return 0;
}
