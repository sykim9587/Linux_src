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
        this->shapeWidth = 0;
    }
    

}

/*

 
        // compute the number of columns to write (as a constant) based on shape type
        int finalShapeWidth;
        if (shapeType == 1)
            {finalShapeWidth = shapeHeight; }    // Compute square width
        else if (shapeType == 2)
            {finalShapeWidth = shapeWidth; }     // Define rectangle width
        else
           {finalShapeWidth = (2*numRows)-1; }   // Compute triangle width
        const string::size_type numCols = finalShapeWidth; // define constant here      
 
 
        // ask for the Shape Fill Style
        int fillStyle;
        for (int keepAsking = 1; keepAsking == 1; )
        {
            cout << "Select Fill Style." << endl;
            cout << "  (1) - Hollow " << endl;
            cout << "  (2) - Solid " << endl;
            cout << "Select Fill Style (enter 1/2): ";
            cin >> fillStyle;
 
            // Make sure the user input is within range. If not, ask again!
            if (fillStyle == 1 || fillStyle == 2)
                {keepAsking = 0;}
        }
 
        // display the shape specification
        cout << endl;
        cout << "Height = " << numRows << " rows." << endl;
        cout << "Width = " << numCols << " columns." << endl;
        cout << endl;
 
        // invariant: we have written r rows so far
        for ( int r = 0; r != numRows; ++r )
        {
            string::size_type c = 0;
 
            // invariant: we have written c characters so far in the current row
            while ( c != numCols)
            {
                // If Square or Rectangle Option
                if (shapeType == 1 or shapeType == 2)
                {
                    // hollow option
                    if (fillStyle == 1)
                    {
                        // Are we at the exact position to output asterisk (border)?
                        if (
                               ( c == 0 )              // the left edge
                            || ( c == numCols-1)       // the right edge
                            || ( r == 0 )              // the top edge
                            || ( r == numRows-1)       // or the bottom edge
                           )
                        { cout << "*"; ++c; }
                        else
                        { cout << ' '; ++c; }
                    }
 
                    // If solid option
                    else if (fillStyle == 2)
                    { cout << "*"; ++c; }
                }
 
                // If Triangle Option
                if (shapeType == 3)
                {
                     // Triangle hollow option
                    if (fillStyle == 1)
                    {
                        // Are we at the exact position to output asterisk (border)?
                        if (
                               ( c == ((numCols-1)/2)-r )  // the triangle left edge
                            || ( c == ((numCols-1)/2)+r )  // or the triangle right edge
                            || ( r == numRows-1)           // or the triangle bottom edge
                           )
                        { cout << "*"; ++c; }
                        else
                        { cout << ' '; ++c; }
                    }
 
                    // If triangle solid option
                    else if (fillStyle == 2)
                    {
                        // Are we at the exact position to output asterisk (solid fill)?
                        if (
                               ( c >= ((numCols-1)/2)-r )  // between the triangle left edge
                            && ( c <= ((numCols-1)/2)+r )  // and the triangle right edge
                           )
                        { cout << "*"; ++c; }
                        else
                        { cout << ' '; ++c; }
                    }
                }
            }
            cout << endl;
        }
 
        // ask user if he would like to start the program again
        cout << "Again? (y/n): ";
        cin >> tryAgain;
    }
    return 0;
}

*/