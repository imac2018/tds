// Compiler avec :
//     g++ -Wall -pedantic -std=c++11 ylcq_td1_td2.cpp
// Puis:
//     ./a.out
//
// Normalement y'a pas besoin de C++11, c'est juste que
// j'utilise une feature qui permet à Vector2Df d'hériter
// des constucteurs de sa classe parent, Point2Df.
//
// -pedantic est pour être sûr que le code est conforme à ISO C++.
// Parce que franchement, vers la fin, j'étais plus sûr du tout.



#include <iostream>// std::cout, etc.
#include <complex> // std::complex<>, std::polar()
#include <cmath>   // sqrtf(), etc.
#include <cstdlib> // EXIT_SUCCESS, malloc/free()
#include <vector>  // std::vector<>
#include <string>  // std::string


// M_PI n'est ni standard, ni un float.
const float PI_F = acosf(-1.f);


// Un truc tout pourri et discriminatoire des autres pays
class Address {
private:
    unsigned postalCode;
    std::string street;
public:
    Address() {}
    ~Address() {}
    void        setStreet(const std::string &s)  { street = s; }
    const std::string& getStreet()     const     { return street; }
    void        setPostalCode(unsigned p) { postalCode = p; }
    unsigned    getPostalCode() const     { return postalCode; }
};

class Person {
private:
    std::string name;
    unsigned age, height;
    Address address;
public:
    Person() {}
    ~Person() {}
    void        setName(const std::string &name) { this->name = name; }
    const std::string& getName()           const { return name; }
    void        setAge(unsigned val)      { age = val; }
    unsigned    getAge()            const { return age; }
    void        setHeigth(unsigned val)   { height = val; }
    unsigned    getHeigth()         const { return height; }
    void        setAddress(const Address &a)     { address = a; }
    const Address& getAddress(void)    const { return address; }
    void        printName()         const { std::cout <<   name << std::endl; }
    void        printAge()          const { std::cout <<    age << std::endl; }
    void        printHeight()       const { std::cout << height << std::endl; }
    void        print()             const { printName(); printAge(); printHeight(); }
};



class Point2Df {
protected: // comme private, mais aussi accessible par les sous-classes.
    float x,y;
    static unsigned num;
public:
    // Construire un Point2Df avec des coordonnées cartésiennes :
    //     Point2Df bar(0.f, 2.f);
    // 
    // Construire un Point2Df avec des coordonnées polaires (magnitude, angle) :
    //     Point2Df foo(std::polar(2.f, PI_F/2.f));
    // 
    // Dans ces exemples, les points foo et bar sont en effet identiques.
    //
    // Autre exemple plus........ **complexe** ?? (toudoum tss)
    //     Point2Df baz(0.5f*cosf(PI_F/3.f), 0.5f*sinf(PI_F/3.f));
    //     Point2Df qux(std::polar(0.5f, PI_F/3.f));
    //
    Point2Df() { ++num; }
    Point2Df(float x, float y) : x(x), y(y) { ++num; }
    Point2Df(std::complex<float> cmplx) {
        x = std::abs(cmplx)*cosf(std::arg(cmplx));
        y = std::abs(cmplx)*sinf(std::arg(cmplx));
        ++num;
    }
    ~Point2Df() { --num; }
    unsigned getTotalCount() const { return num; }
    void  printCartesian() const { std::cout << "{ x: " << x << ", y: " << y << " }" << std::endl; }
    void  print()          const { printCartesian(); }
    void  printPolar()     const { /* TODO, mais au final c'est pas demandé. */ }
    float getX()           const { return x; }
    float getY()           const { return y; }
    void  setX(float xx)         { x = xx; }
    void  setY(float yy)         { y = yy; }
    static float distance(const Point2Df &a, const Point2Df &b) {
        Point2Df v(b.x-a.x, b.y-a.y);
        return sqrtf(v.x*v.x + v.y*v.y);
    }
    float distanceFrom(const Point2Df &p) const { return distance(*this, p); }
    void translate(float xx, float yy) { x += xx, y += yy; };
    // Non testé
    void operator+=(const Point2Df &p) { translate(p.x, p.y); }
};


// Ne pas oublier ça !
unsigned Point2Df::num = 0;


// 5. Vector doit hériter de Point.
class Vector2Df : public Point2Df {
    // float x,y; 
    // Hérités de Point2Df, et accessibles
    // car leur visibilité est 'protected' et non 'private'.
public:
    // C++11: Hériter des constructeurs de la classe parent.
    // Sans C++11, il faudrait manuellement réécrire un constructeur.
    //
    using Point2Df::Point2Df; 

    // Il demande "scalar product", mais le nom "dot product" est simplement plus répandu.
    static float dotProduct(const Vector2Df &u, const Vector2Df &v) {
        return u.x*v.x + u.y*v.y;
    }
    float     dotProductWith(const Vector2Df &v) const { return dotProduct(*this, v); }
    Vector2Df add(const Vector2Df &v)            const { return Vector2Df(x+v.x, y+v.y); }
    Vector2Df sub(const Vector2Df &v)            const { return Vector2Df(x-v.x, y-v.y); }
    float     getEuclidianNorm()                 const { return sqrtf(x*x + y*y); }
    float     getLength()                        const { return getEuclidianNorm(); }
    static float cosineSimilarity(const Vector2Df &u, const Vector2Df &v) {
        return dotProduct(u, v) / (u.getEuclidianNorm() * v.getEuclidianNorm());
    }
    float cosineSimilarityWith(const Vector2Df &v) const { 
        return cosineSimilarity(*this, v); 
    }
    // void print() {} // Pas besoin, on en hérite.
};



class LineSegment2Df {
private:
    Point2Df a, b;
public:
     LineSegment2Df() {}
    ~LineSegment2Df() {}
    Point2Df getA()      const { return a; }
    Point2Df getB()      const { return b; }
    void     setA(const Point2Df &aa) { a = aa; }
    void     setB(const Point2Df &bb) { b = bb; }
    float    getLength() const { return a.distanceFrom(b); }
    void     print()     const { 
        std::cout << "{ a: "; a.print();
        std::cout << ",  b: "; b.print();
        std::cout << " }" << std::endl;
    }
};


// Il est demandé une classe abstraite GeoObject.
// On dit d'une classe qu'elle est abstraite quand elle est trop générale
// pour être instanciée telle quelle. En d'autres termes, on ne veut pas
// pouvoir l'instancier, mais seulement en hériter.
//
// Dans la suite de ce commentaire, entendez 'méthode' comme
// 'méthode ou destructeur'.
//
// La clé ici, c'est le destructeur virtuel :
//     virtual ~GeoObject2Df();
// 'virtual' est un qualificateur de méthode qui indique que celle-ci *devrait*
// être implémentée par toute classe fille (mais pas forcément).
// En pratique, c'est implémenté par un pointeur de fonction. Ca veut dire deux
// choses :
// - Chaque instance de votre objet pèse de 32 à 64 bits de plus par 
//   fonction virtuelle (la taille d'un pointeur);
// - Quand vous appelez une méthode dont la méthode héritée est 'virtual',
//   le code à appeler dépend de ce pointeur. C'est mauvais pour certaines
//   raison, en autres que le cache d'instructions du CPU n'aime pas trop ça.
//
// Dans la mesure du possible, il faut donc éviter d'avoir à qualifier 
// des méthodes de 'virtual' (ça signifie immédiatement d'éviter l'héritage).
//
// le '= 0' après une méthode 'virtual' sert à indiquer que c'est une méthode
// 'virtual pure'. En gros, ça force toute classe fille à implémenter cette
// méthode.
class GeoObject2Df {
private:
    static unsigned num;
public:
    GeoObject2Df()           { ++num; }
    virtual ~GeoObject2Df()  { --num; } //Destructeur
    unsigned getTotalCount()     const { return num; }
    virtual float getPerimeter() const = 0;
    virtual float getArea()      const = 0;
    virtual void  print()        const = 0;
};

unsigned GeoObject2Df::num = 0;

// Le '#if 0 ... #endif' fait que tout texte entre les deux est ignoré.
// Pour savoir pourquoi, réviser le cours sur les phases de compilation en C.
// Si vous remplacez par '#if 1' vous verrez l'erreur de compilation.
#if 0
GeoObject2Df caNeCompileraPasEtTantMieuxCarCestUneClasseAbstraite;
#endif

static void print(const GeoObject2Df &obj) {
    obj.print(); // Wow, cette fonction appelle la plus spécialisée !
    //obj.getRadius(); //non, on peut pas
}

class Circle2Df : public GeoObject2Df {
private:
    Point2Df center;
    float radius;
public:
    Circle2Df(){}
    ~Circle2Df(){}
    float getDiameter()  const { return 2.f*radius; }
    float getRadius()    const { return radius; }
    float getPerimeter() const { return 2.f*PI_F*radius; }
    float getArea()      const { return PI_F*radius*radius; }
    void  print()        const {
        std::cout << "{ center: "; center.print();
        std::cout << ", radius: " << radius << " }" << std::endl;
    }
};

class Rectangle2Df : public GeoObject2Df {
private:
    Point2Df center;
    Vector2Df size;
    float rotation; // Ce n'est pas demandé, mais je trouve que ça a du sens.
                    // Sinon, ça serait une AABB (Axis-Aligned Bounding Box).
public:
    Rectangle2Df() {}
    ~Rectangle2Df() {}
    float getArea()      const { return size.getX()*size.getY(); }
    float getPerimeter() const { return 2.f*(size.getX() + size.getY()); }
    float getDiagonal()  const { return size.getLength(); }
    void  print()        const {
        std::cout << "{ center: "; center.print();
        std::cout << ", size: "; size.print();
        std::cout << ", rotation: " << rotation << " }" << std::endl;
    }
};


static void test_geoobj_count_helper(void) {
    static const size_t c_cnt = 4, r_cnt = 8;
    Circle2Df circs[c_cnt];
    Rectangle2Df rects[r_cnt];
    std::cout << "   Circle count : " << circs[0].getTotalCount() << "(was " << c_cnt << ")" << std::endl;
    std::cout << "Rectangle count : " << rects[0].getTotalCount() << "(was " << r_cnt << ")" << std::endl;
}

static void test_geoobj_count(void) {
    static const size_t c_cnt = 3, r_cnt = 7;
    Circle2Df circs[c_cnt];
    Rectangle2Df rects[r_cnt];
    std::cout << "   Circle count : " << circs[0].getTotalCount() << "(was " << c_cnt << ")" << std::endl;
    std::cout << "Rectangle count : " << rects[0].getTotalCount() << "(was " << r_cnt << ")" << std::endl;
    test_geoobj_count_helper();
    std::cout << "   Circle count : " << circs[0].getTotalCount() << "(was " << c_cnt << ")" << std::endl;
    std::cout << "Rectangle count : " << rects[0].getTotalCount() << "(was " << r_cnt << ")" << std::endl;
}




typedef Point2Df Vertex2Df;

class Polygon2Df {
private:
    std::vector<Vertex2Df> vertices; // Le premier sommet est aussi le dernier.
public:
    Polygon2Df() {}
    ~Polygon2Df() {}
    // XXX Cette fonction pré-suppose que notre polygone est convexe.
    //     Les angles concaves seront erronés. Je compte pas changer ça.
    const std::vector<float> getInnerAnglesList() { 
        std::vector<float> angles;
        const size_t v_count = vertices.size();
        for(size_t i=0 ; i<v_count ; ++i) {
            //
            //            v1
            //           .
            //          / \     -
            //         /\_/\ <--- L'angle qu'on calcule.
            //        /     \   -
            //       /       \  -
            // . __ .         . ____ .
            //       v0        v2
            //
            const Vertex2Df &v0 = vertices[(i+v_count-1)%v_count];
            const Vertex2Df &v1 = vertices[i];
            const Vertex2Df &v2 = vertices[(i+1)%v_count];
            // Argh. Ca mériterait un constructeur dédié.
            const Vector2Df u(v0.getX()-v1.getX(), v0.getY()-v1.getY());
            const Vector2Df v(v2.getX()-v1.getX(), v2.getY()-v1.getY());
            angles.push_back(acosf(Vector2Df::cosineSimilarity(u, v)));
        }
        return angles;
    }
    float getPerimeter() { 
        float perim = 0.f;
        size_t i; 
        for(i=1 ; i<vertices.size() ; ++i)
            perim += vertices[i-1].distanceFrom(vertices[i]);
        perim += vertices[i-1].distanceFrom(vertices[0]);
        return perim;
    }
    void print() {
        size_t i; 
        std::cout << "{";
        for(i=0 ; i<vertices.size()-1 ; ++i)
            std::cout << "v" << i << ": ", vertices[i].print(), std::cout << ", ";
        std::cout << "v" << i << ": ", vertices[i].print();
        std::cout << "}" << std::endl;
    }
};

class DynamicPolygon2Df {
private:
    Vertex2Df *vertices;
public:
    DynamicPolygon2Df(size_t count) { 
        vertices = (Vector2Df*) malloc(count*sizeof *vertices); 
        //Equivalent : vertices = (Vector2Df*) malloc(count*sizeof(Vector2Df)); 
        // XXX Vérifier si l'appel a réussi, donc que vertices != NULL.
    }
    ~DynamicPolygon2Df()            { free(vertices); }
};


// 7. class vs. struct !

struct Comestible {
private: // Tiens, on a le droit de mettre private ici ??
    unsigned hp;
public:
    // Et des constructeurs et destructeurs ??
    Comestible() {}
    Comestible(unsigned hp) : hp(hp) {}
    virtual ~Comestible() {}
    // Whoops, méthodes virtuelles ??
    virtual void getEatenBy(Comestible &c) const {
        std::cout << "NOOOOOOOO" << std::endl;
    }
    // Virtuelles pures ??
    virtual void print() const = 0;
};

struct Dinosaur : public Comestible { // omfg on peut hériter d'une struct
private:
    unsigned hp, stamina;
public:
    // Des membres static ??
    // Ca devient embarassant...
    static const unsigned HP_REGEN = 200;
    static const unsigned STAMINA_REGEN = 500;
    // Ah bah tiens ! Des méthodes dans une struct !
    bool eat(Comestible &c) { 
        //c.hp -= 1000; // On peut pas toucher, c'est private !
        hp += HP_REGEN;
        stamina += STAMINA_REGEN;
        c.getEatenBy(*this);
        return true; 
    }
    void sleep() { 
        std::cout << "ZZZZzzzz (dinosaur's sleeping.)" << std::endl; 
    }
    void print() const { 
        std::cout << "Yep, that's a legit dinosaur." << std::endl; 
    }
};

static Dinosaur paris;         // #DinosaurKing
static struct Dinosaur denver; // Le dernier diiinosaaaaure ! 
                               // C'est mon ami et bien plus encore !
static Circle2Df cercleDeSatan;
static class Circle2Df jeSaisPas;
// Ah bah en fait on peut instancier des structs ou class en les préfixant
// par ces mots-clés. Ehhh...


// Et ça ? (edit: putain sérieux ça passe ça ?? Mais c'est quoi ce langage ?)
static struct Circle2Df blaspheme;
static class Dinosaur whatTheFckOmfg;


template <class T> void print_obj(T t) { t.print(); }
// Ahah ! La ligne suivante ne compile pas ! C'est une différence !
// template <struct T> void template_toast_struct(T t) {}

static void inutile() {
    print_obj<Circle2Df>(cercleDeSatan);
    print_obj<Circle2Df>(jeSaisPas);
    print_obj<Circle2Df>(blaspheme);
    print_obj<Dinosaur>(denver);
}

// Au final j'ai pas pu résister à chercher sur Google :
// La seule différence, à part la dernière ci-dessus, c'est que la visibilité
// par défaut des membres dans une struct est 'public' (vs 'private' pour 
// une class).

int main(void) {
    inutile();
    test_geoobj_count();
    print(Circle2Df());
    print(Rectangle2Df());
    return EXIT_SUCCESS;
}
