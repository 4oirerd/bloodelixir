import js.Browser;
import js.html.Element;
import js.html.CanvasElement;
import js.html.webgl.WebGL2RenderingContext;
import Wgl2Root;


class Root
{
    static function main()
    {
        var glinfo:Wgl2Root = new Wgl2Root();
        Browser.window.onload = function()
        {
            glinfo.canvas = cast Browser.document.getElementById("canvas");
            glinfo.canvas.setAttribute("width", Std.string(glinfo.width));
            glinfo.canvas.setAttribute("height", Std.string(glinfo.height));
            glinfo.gl = cast glinfo.canvas.getContext("webgl2");
        }
    }
}
