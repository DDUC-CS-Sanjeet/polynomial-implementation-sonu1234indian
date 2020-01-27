#include<iostream>
using namespace std;

class Polynomial
{
  private:
	  	int  a[100];
  		int degree;		
  		
    // Variables to store information about polynomial
  public:

    Polynomial()
    {
    	degree=1;
    }

    Polynomial(int deg)
    {
    	// Behavior of constructor with arguments
    	cout<<"Enter degree of "<<deg<< " Polynomial ";
 		 cin>>degree;
 		 degree++;
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
    }
    
    //  Overload copy constructor, +, - and = operators
    Polynomial operator +(Polynomial c)
    {
    	Polynomial p;
		p.degree= this->degree>=c.degree? this->degree:c.degree;    	
		for(int i=0;i<p.degree;i++)
		{
			if(i>=this->degree)
				this->a[i]=0;
			if(i>=c.degree)
				c.a[i]=0;
				p.a[i]=c.a[i]+this->a[i];
		}
		return p;
	}

	Polynomial operator -(Polynomial c)
    {
    	Polynomial p;
		p.degree= this->degree>=c.degree? this->degree:c.degree;    	
		for(int i=0;i<p.degree;i++)
		{
				if(i>=this->degree)
				this->a[i]=0;
				if(i>=c.degree)
				c.a[i]=0;
				p.a[i]=this->a[i]-c.a[i];
		}
    		
    	
    	return p;
	}
	
	Polynomial operator =(Polynomial c)
    {
    	this->degree=c.degree;
    	for(int i=0;i<this->degree;i++)
    		this->a[i]=c.a[i];
    	
	}
    
    void storePolynomial()
    {
      //  Code to enter and store polynomial	
      	
     	cout<<"Enter the cofficient of x0,x1,x2....respectively ";
		for(int i=0;i<degree;i++)
			cin>>a[i];
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      cout<<"\n";
      for(int i=0;i<degree;i++)
      {
       	cout<<a[i]<<"X^"<<i;
       	if(i<degree-1)
       		cout<<" + ";
	  }
      	
    }
  
};

int main()
{
  int degFirst=1, degSecond=2;
  // Ask user to input the values of degFirst and degSecond 
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  cout<<"\n your 1st polynomial is : ";
  firstPolynomial.display();
  cout<<"\n your 2nd polynomial is : ";
  secondPolynomial.display();
  cout<<"\n polynomial after addition : ";
  thirdPolynomial.display();
  cout<<"\n polynomial after subtraction : ";
  fourthPolynomial.display();
}

