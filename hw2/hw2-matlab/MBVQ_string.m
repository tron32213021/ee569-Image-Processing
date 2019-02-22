%copyright: ZhenyeJiang, zhenyeji@usc.edu
function Q = MBVQ_string(p)
    r=double(p(1));g=double(p(2));b=double(p(3));
    if((r+g)>255)
        if((g+b)>255)
            if((r+g+b)>510)
                Q="cmyw";
            else
                Q="mygc";
            end
        else
            Q="rgmy";      
        end
    else
        if(~((g+b)>255))
            if(~((r+g+b)>255))
                Q="krgb";
            else
                Q="rgbm";
            end
        else
            Q="cmgb";
        end
    end     
end

