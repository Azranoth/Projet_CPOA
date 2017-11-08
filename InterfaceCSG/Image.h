#ifndef IMAGE_H
#define IMAGE_H

template <typename T>
class Image{

    protected :
        int largeur;
        int hauteur;
        T* data;

    private :
        Image(Image const &);
        Image& operator=(Image const &);

    public :
        inline Image(int l, int h){
            largeur=l;
            hauteur=h;
            data = new T[l*h];
        }

        Image(const Image& im) = delete;

        ~Image(){
            delete[] data;
        }

        int width() const {return largeur;}
        int height() const {return hauteur;}
        T* data_pix() { return data;}


        T& operator ()(int i,int j) { return data[i+j*largeur];}

        const T& operator ()(int i,int j) const { return data[i+j*largeur];}

        void swap_pixels(Image<T>& im)
        {
            assert(im.width()==this->width() && im.height()==this->height());
            std::swap(im.data,this->data);
        }

        void convol3x3(const double* m)
        {
            Image<T> im(largeur,hauteur);

            for(int j=1;j<hauteur-1;j++)
                for(int i=1;i<largeur-1;i++)
                {
                    double v = 0;
                    const double* p = m;
                    for(int l=-1;l<2;l++)
                        for(int k=-1;k<2;k++)
                            v += (*this)(i+k,j+l)*(*p++);
                    im(i,j) = T(v);
                }

            // copie du bord
            for(int j=0;j<hauteur;j++)
            {
                im(0,j) = (*this)(0,j);
                im(largeur-1,j) = (*this)(largeur-1,j);
            }

            for(int i=0;i<largeur;i++)
            {
                im(i,0) = (*this)(i,0);
                im(i,hauteur-1) = (*this)(i,hauteur-1);
            }

            swap_pixels(im);
        }
};

/// version pour les types (P)Array
/// le type P doit fournir [] -> type numeric, et size()
template <typename P>
auto convol3x3(Image<P>& image, const double* m) -> typename std::enable_if<!std::is_arithmetic<P>::value,void>::type
{

    int w = image.width();
    int h = image.height();

    Image<P> im(imageconst .width(),image.height());

    for(int j=1;j<h-1;j++)
        for(int i=1;i<w-1;i++)
        {
            P v;
            for(int iv=0; iv<v.size(); ++iv)
                v[i]=0;
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                {
                    auto& u = image(i+k,j+l);
                    for(int iv=0; iv<v.size(); ++iv)
                        v[i] += u[i] * (*p);
                    p++;
                }
            im(i,j) = v;
        }

    for(int j=0;j<h;j++)
    {
        im(0,j) = image(0,j);
        im(w-1,j) = image(w-1,j);
    }

    for(int i=0;i<w;i++)
    {
        im(i,0) = image(i,0);
        im(i,h-1) = image(i,h-1);
    }

    image.swap_pixels(im);
}

/// version pour les types (P) numériques
template <typename P>
auto convol3x3(Image<P>& image, const double* m) -> typename std::enable_if<std::is_arithmetic<P>::value,void>::type
{
    int w = image.width();
    int h = image.height();

    Image<P> im(image.width(),image.height());

    for(int j=1;j<h-1;j++)
        for(int i=1;i<w-1;i++)
        {
            P v(0);
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                    v += image(i+k,j+l)*(*p++);
            im(i,j) = v;
        }

    for(int j=0;j<h;j++)
    {
        im(0,j) = image(0,j);
        im(w-1,j) = image(w-1,j);
    }

    for(int i=0;i<w;i++)
    {
        im(i,0) = image(i,0);
        im(i,h-1) = image(i,h-1);
    }

    image.swap_pixels(im);
}


#endif
