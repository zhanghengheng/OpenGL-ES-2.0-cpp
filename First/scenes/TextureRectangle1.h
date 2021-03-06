#pragma  once

#include "gl_include.h"
#include "ELShaderProgram.h"
#include <string>

NS_BEGIN(elloop);


class TextureRectangle1 : public ShaderProgram
{
public:
    static TextureRectangle1*   create();
    void                        begin()     override;
    void                        end()       override;
    void                        render()    override;

    uniform                     mvp_;
    uniform                     texture_;
    attribute                   position_;
    attribute                   uv_;

    unsigned int                textureId_;

protected:

    struct Vertex
    {
        CELL::float2      pos;
        CELL::float2      uv;
    };

    bool                        init();
    TextureRectangle1()
        : mvp_(-1)
        , texture_(-1)
        , textureId_(-1)
        , position_(-1)
        , uv_(-1)
    {
        vsFileName_ = "shaders/texture_rect_vs.glsl";
        fsFileName_ = "shaders/texture_rect_fs.glsl";
    }
    ~TextureRectangle1()
    {}

    unsigned int loadTexture(const std::string &fileName);
};



NS_END(elloop);