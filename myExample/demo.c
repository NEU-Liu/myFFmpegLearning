#include <stdio.h>
#include "../myFFmpeg/include/libavformat/avformat.h"
#include "../myFFmpeg/include/libavcodec/avcodec.h"
#include "../myFFmpeg/include/libavdevice/avdevice.h"

int main() {
    av_register_all();
    AVInputFormat *inputFormat = av_iformat_next(NULL);
    AVOutputFormat *outputFormat = av_oformat_next(NULL);
    while (inputFormat) {
        printf("[In][%10s]\n", inputFormat->name);
        inputFormat = inputFormat->next;
    }
    while (outputFormat) {
        printf("[Out][%10s]\n", outputFormat->name);
        outputFormat = outputFormat->next;
    }

    AVCodec *codec = av_codec_next(NULL);
    while (codec) {
        if (codec->decode) {
            printf("[Dec]");
        } else {
            printf("[Eec]");
        }
        switch (codec->type) {
            case AVMEDIA_TYPE_VIDEO:
                printf("[Video]");
                break;
            case AVMEDIA_TYPE_AUDIO:
                printf("[Audio]");
                break;
            default:
                printf("[Other]");
                break;
        }
        printf("[%10s]\n", codec->name);
        codec = codec->next;
    }

    avfilter_register_all();
    // AVFilter    *filter  = avfilter_next(NULL);
    // while (filter) {
    //     printf("[F][%s]\n", filter->name);
    //     filter = filter->next;
    // }   
  return 0;
}
