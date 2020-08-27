#include "shapes.h"

void Shape::print_intro()
{
    cout << endl;
    cout << "*********************************" << endl;
    cout << "*** The Shape Making Program  ***" << endl;
    cout << "*********************************" << endl;
    cout << endl; 
}

void Shape::menu()
{
    bool tryagain = false;
    while(this->shapeType != 1 && this->shapeType !=2 && this->shapeType != 3)
    {
        cout << "Select the Shape Type." << endl;
        cout << "  (1) - Square " << endl;
        cout << "  (2) - Rectangle " << endl;
        cout << "  (3) - Triangle " << endl;
        cout << "Shape Type (enter 1/2/3): ";
        if (tryagain){  // to ignore this part when it's the first time
            std::cin.clear();   //changes the internal state of the stream - unsets the error flag.
            std::cin.ignore();  //extracts and discards unwanted values.
        }
        cin >> this->shapeType;
        tryagain = true;

    }

}

void Shape::size()
{
    cout << "Enter Shape Height: ";
    cin >> this->shapeHeight;

    if (this->shapeType == 2)
        {
            // ask for the shape width
            cout << "Enter Shape Width: ";
            cin >> this->shapeWidth;
        }
    else
    {
        cout<<"not asking"<<endl;
        if (this->shapeType == 1 ){
            this->shapeWidth = this->shapeHeight;
        }
        else
        {
            this->shapeWidth = (2*this->shapeHeight)-1;
        }
        
    }
    

}

void Shape::fill_style()
{

    cout << "Select Fill Style." << endl;
    cout << "  (1) - Hollow " << endl;
    cout << "  (2) - Solid " << endl;
    cout << "Select Fill Style (enter 1/2): ";
    cin >> this->fillstyle;
    
    while(this->fillstyle != 1 && this->fillstyle != 2)
    {
        cout<<"wrong input, type again (1 or 2):";
        
        std::cin.clear();   //changes the internal state of the stream - unsets the error flag.
        std::cin.ignore();  //extracts and discards unwanted values.
        
        cin >>this->fillstyle;
    }

}

void Shape::dislay_info()
{
    cout << "*Shape Information*"<<endl;
    cout<< "height and width: "<< this->shapeHeight<< ", "<< this->shapeWidth<<endl;
    cout<< "fill style (hollow: 1, filled: 2): "<< this->fillstyle<<endl;
    cout <<endl;
}

void Shape::draw()
{
    int numRows = this->shapeHeight;
    int numCols = this->shapeWidth;
    int type = this->shapeType;
    int fillT = this->fillstyle;

    for (int r = 0; r != numRows; ++r)
    {
        int c = 0;
        while (c != numCols)
        {
            if (type == 1 || type == 2)     //square or rectangle
            {
                if (r==0 || r==numRows-1) //boundary
                {
                    cout<< string(numCols, '*');
                    c += numCols;
                }
                else //other lines
                {
                    if(fillT == 1) //hollow
                    {
                        cout<<"*"<<string(numCols-2,' ')<<"*";
                        c+=numCols;
                    }
                    else //filled
                    {
                        cout<< string(numCols, '*');
                        c += numCols;
                    }
                    
                }
                
            }
            else                            //triangle
            {
                if(fillT == 1)  //hollow
                {
                    if (r==0 || r== numRows-1)                 //the starting point
                    {
                        if (r== numRows-1)
                            cout << string(r*2+1,'*')<<endl;    //print the whole line 
                        else
                        {
                            cout<<string(numCols/2,' ')<<"*";
                        }
                        
                        c = numCols;
                    }
                    else if((c == numCols/2 - r)||(c == numCols/2 + r))  //other rows 
                    {
                        cout<<"*";
                        c += 1;
                    }
                    else
                    {
                        cout<<" ";
                        c += 1;
                    }
                }
                else            //filled
                {
                    if (c == numCols/2 - r)                 //the starting point
                    {
                        cout << string(r*2+1,'*')<<endl;    //print the whole line 
                        c = numCols;
                    }
                    else
                    {
                        cout<<" ";
                        c += 1;
                    }
                    
                }
                
            }
            
        }
        cout<<endl;
    }
}
