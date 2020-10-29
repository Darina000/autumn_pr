//  Created by Дарья Землянская on 28.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

#include <exception>


class MyException: public std::exception{
private:
    std::string m_error;
public:
    MyException(std::string error)
        : m_error(error)
    {
    }
    const char* what() const noexcept { return m_error.c_str(); }
};



struct Point{
    double x;
    double y;
};


class Figure {
public:
    
        Figure(const std::vector<Point>& arrr):
    aray(arrr) {
        }

        virtual ~Figure() = default;
        virtual double calc_square() const = 0;
        virtual double calc_perimeter() const = 0;
        friend std::ostream& operator<< (std::ostream &out, const Figure &figure);

protected:
        virtual void Print(std::ostream &out) const = 0;
        std::vector <Point> aray;
};



std::ostream& operator<< (std::ostream &out, const Figure &figure){
    try{
        figure.Print(out);
    }
    catch(MyException &c){
        std::cout << c.what();
    }
    catch(std::exception &c){
        std::cerr << "Other std::exception occurred: " << c.what() << std::endl;
    }
    out<< std::endl;
    return out;
}

double distance(const Point &pair1, const Point &pair2) {
    
    double dist =  sqrt(pow((pair1.x-pair2.x), 2)+pow((pair1.y-pair2.y), 2));
    if (dist < 0 ){
        throw (MyException("Invalid dist"));
    }
    return dist;
}


class Triangle: public Figure {
    public:
        Triangle(const std::vector<Point>& arrr):Figure(arrr){
            try{
                m_a = distance(arrr[0], arrr[1]);
                m_b = distance(arrr[1], arrr[2]);
                m_c = distance(arrr[2], arrr[0]);
            }
            catch(MyException &c){
                std::cout << c.what();
            }
            catch (std::exception &exception)
            {
                std::cerr << "Triangle_Other std::exception occurred: " << exception.what() << std::endl;
            }
        }
    
    
        ~Triangle() = default;
    
        virtual double calc_square() const override {
            double m_p = (m_a + m_b + m_c)/2;
                if(m_p<=0){
                    throw "Triangle_Error in calc_square";
                }
            return sqrt(m_p*(m_p - m_a) * (m_p - m_c) * (m_p - m_b));
        }
 
        virtual double calc_perimeter() const override{
            if ((m_a + m_b + m_c)<=0){
                throw MyException("Triangle_Error in calc_perimeter");
            }
            return m_a + m_b + m_c;
        }
    
    protected:
        virtual void Print(std::ostream &out) const override{
            try{
            out << "Side: "<< m_a << " " << m_b << " " << m_c << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
            }
            catch(MyException &c){
                std::cout << c.what();
            }
            catch (std::exception &exception)
            {
                std::cerr << "Triangle_Other std::exception occurred: " << exception.what() << std::endl;
            }
        }
    private:
        double m_a;
        double m_b;
        double m_c;
};
 

class Ellipce: public Figure {
    public:
        Ellipce(const Point O, double o_a, double o_b):Figure({O}), a(o_a), b(o_b){
        }
        ~Ellipce() = default;
    
        virtual double calc_square() const override{
            if((M_PI * a * b)<=0){
                throw MyException("Ellipce_error in calc_square");
            }
            return  M_PI * a * b;
        }
 
        virtual double calc_perimeter() const override{
            if ((4 * (M_PI * a*b +(a-b)*(a-b))/(a+b))<=0){
                throw MyException("Ellipce_error in calc_perimeter");
            }
            return 4 * (M_PI * a*b +(a-b)*(a-b))/(a+b);
        }
    protected:
        virtual void Print(std::ostream &out) const override{
            try{
            out << "Center: "<< aray[0].x << " " << aray[0].y << std::endl;
            out << "Half-shafts: "<< a << " " << b << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
            }
            catch(MyException &c){
               std::cout << c.what();
                }
            catch (std::exception &exception)
                {
                    std::cerr << "Ellipce_error std::exception occurred: " << exception.what() << std::endl;
                }
        }
    protected:
        double a;
    private:
        double b;
};



class Circle: public Ellipce {
    public:
    Circle(const Point O, double o_a): Ellipce(O, o_a, o_a ){
        }
    
        ~Circle() = default;
    
        virtual double calc_perimeter() const override{
            if((2 * M_PI * a)<=0){
                throw MyException("Circle_error: calc_perimeter");
            }
            return 2 * M_PI * a;
        }
        virtual double calc_square() const override{
            if((M_PI * a * a)<=0){
                throw MyException("Circle_error: calc_square");
            }
            return  M_PI * a * a;
           }
    protected:
        virtual void Print(std::ostream &out) const override{
            try{
            out << "Center: "<< aray[0].x << " " << aray[0].y << std::endl;
            out << "Radius: "<< a << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
            }
            catch(MyException &c)
            {
               std::cout << c.what();
            }
            catch(std::exception &exception)
            {
                std::cerr << "Circle_errror std::exception occurred: " << exception.what() << std::endl;
            }
        }
};



class Quadrangle: public Figure {
    public:
        Quadrangle(const std::vector<Point>& arrr):Figure(arrr){
            try{
            a = distance(arrr[0], arrr[1]);
            b = distance(arrr[1], arrr[2]);
            c = distance(arrr[2], arrr[3]);
            d = distance(arrr[3], arrr[0]);
            m_q = distance(arrr[0], arrr[2]);
            }
            catch(MyException &c){
                std::cout << c.what();
            }
            catch(std::exception &exception)
            {
                std::cerr << "Quadrangle_error std::exception occurred: " << exception.what() << std::endl;
            }
        }
        ~Quadrangle() = default;
    
        virtual double calc_square() const override{
            
            double m_p1 = a + b + m_q;
            if (m_p1 <=0){
                throw MyException("Quadrangle_error in m_p1");
            }
            double m_p2 = c + d + m_q;
            if (m_p1 <=0){
                throw MyException("Quadrangle_error in m_p2");
            }
            double s1 = sqrt(m_p1 * (m_p1 - a) * (m_p1 - b) * (m_p1 - m_q));
            if (m_p1 <=0){
                throw MyException("Quadrangle_error in s1");
            }
            double s2 = sqrt(m_p2 * (m_p2 - c) * (m_p2 - d) * (m_p2 - m_q));
            if (m_p1 <=0){
                throw MyException("Quadrangle_error in s2");
            }
            return s1+s2;
        }
 
        virtual double calc_perimeter() const override{
            if (a + b + c + d <=0){
                throw MyException("Quadrangle_error in calc_perimeter");
            }
            return a + b + c + d;
        }
    protected:
        virtual void Print(std::ostream &out) const override{
            try{
            out << "Side: "<< a << " " << b << " " << c << " " << d << std::endl;
            out << "Perimeter: " << calc_perimeter() << std::endl;
            out << "Square: " << calc_square() << std::endl;
            }
            catch(MyException &c){
                std::cout << c.what();
                }
            catch(std::exception &exception)
                {
                    std::cerr << "Quadrangle_error std::exception occurred: " << exception.what() << std::endl;
                }
        }
    private:
        double a;
        double b;
        double c;
        double d;
        double m_q;
};

 
class Rectangle: public Quadrangle{
 
    public:
        Rectangle(const std::vector<Point>& arrr): Quadrangle(arrr){
            try{
            a = distance(arrr[0], arrr[1]);
            b = distance(arrr[1], arrr[2]);
            }
            catch(MyException &c){
                std::cout << c.what();
                }
            catch(std::exception &exception)
                {
                    std::cerr << "Rectangle_error std::exception occurred: " << exception.what() << std::endl;
                }
        }
        ~Rectangle() = default;
    
        virtual double calc_square() const override{
            if ((a*b)<=0){
                throw MyException("Rectangle_error in calc_square");
            }
            return a * b;
        }
    private:
        double a, b;
};
 

class Square: public Rectangle{
    public:
        Square(const std::vector<Point>& arrr): Rectangle(arrr){
            try{
            a = distance(arrr[0], arrr[1]);
            }
            catch(MyException &c){
                std::cout << c.what();
                    }
            catch(std::exception &exception)
                    {
                std::cerr << "Square_error std::exception occurred: " << exception.what() << std::endl;
                    }
        }
        ~Square() = default;
       virtual double calc_perimeter() const override{
           if((4*a)<= 0){
               throw MyException("Square_error in calc_perimeter");
           }
            return 4 * a;
        }
    private:
        double a;
};
 



int main() {
    Point t1{0, 3};
    Point t2{0, 0};
    Point t3{4, 0};

    Point el_1{5, 1};
    Point el_2{-4, 2};
    Point el_3{-3, 0};
    Point el_4{0, -2};
    
    std::vector<Point> triang ={t1, t2, t3};
    std::vector<Point> quad ={el_1, el_2, el_3, el_4};
    std::vector<Point> rec ={t1, t2, t3, el_1};
    std::vector<Point> squa ={t1, t2};
    
    Triangle triangle(triang);
    std::cout << triangle;
    
    Ellipce ellipce(t2, 5, 7);
    std::cout << ellipce;
    
    Circle circle(t3, 5);
    std::cout << circle;
    
    Quadrangle quadrangle(quad);
    std::cout << quadrangle;
    
    Rectangle rectangle(rec);
    std::cout << rectangle;
    
    Square square(squa);
    std::cout << square;
    
    Figure *masssive1[4] = { &triangle, &ellipce, &circle, &quadrangle};
    std::vector <Figure*> masssive2 = { &triangle, &ellipce, &circle, &quadrangle};
}
