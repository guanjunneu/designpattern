#include <vector>
#include <iostream> // std::cout
#include <memory> // std::auto_ptr
#include <algorithm> // std::for_each
using namespace std;
 
class Graphic
{
public:
  virtual void print() const = 0;
  virtual ~Graphic() {}
};
 
class Ellipse : public Graphic
{
public:
  void print() const {
    cout << "Ellipse \n";
  }
};
 
class Square : public Graphic
{
public:
  void print() const {
    cout << "Square \n";
  }
};

class Circle : public Graphic
{
public:
  void print() const {
    cout << "Circle \n";
  }
};

class Triangle : public Graphic
{
public:
  void print() const {
    cout << "Triangle \n";
  }
};
class CompositeGraphic : public Graphic
{
public:
  void print() const {
    // for each element in graphicList_, call the print member function
    for_each(graphicList_.begin(), graphicList_.end(), [](Graphic* a){a->print();});
  }
 
  void add(Graphic *aGraphic) {
    graphicList_.push_back(aGraphic);
  }
 
private:
  vector<Graphic*>  graphicList_;
};
 
int main()
{
  // Initialize four ellipses
  const auto_ptr<Ellipse> ellipse1(new Ellipse());
  const auto_ptr<Circle> ellipse2(new Circle());
  const auto_ptr<Square> ellipse3(new Square());
  const auto_ptr<Triangle> ellipse4(new Triangle());
 
  // Initialize three composite graphics
  const auto_ptr<CompositeGraphic> graphic(new CompositeGraphic());
  const auto_ptr<CompositeGraphic> graphic1(new CompositeGraphic());
  const auto_ptr<CompositeGraphic> graphic2(new CompositeGraphic());
 
  // Composes the graphics
  graphic1->add(ellipse1.get());
  graphic1->add(ellipse2.get());
  graphic1->add(ellipse3.get());
 
  graphic2->add(ellipse4.get());
 
  graphic->add(graphic1.get());
  graphic->add(graphic2.get());
 
  // Prints the complete graphic (four times the string "Ellipse")
  graphic->print();
  return 0;
}
