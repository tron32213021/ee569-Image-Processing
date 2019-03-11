%copyright: ZhenyeJiang, zhenyeji@usc.edu
function  G  = readraw( filename,height,width,channel )
    fid=fopen(filename,'rb');
    if (fid == -1)
	  	error('can not open input image file press CTRL-C to exit \n');
	  	pause;
    end
    pixels = fread(fid, inf, 'uchar');
    fclose(fid);
    
    if nargin<4 
        channel=1;
    end
    G = zeros(channel,width,height);
    G(1:height*width*channel)=pixels(1:height*width*channel);
    G=uint8(permute(G,[3,2,1]));
    if nargin<4 
        G=reshape(G,[height,width]);
    end
end

