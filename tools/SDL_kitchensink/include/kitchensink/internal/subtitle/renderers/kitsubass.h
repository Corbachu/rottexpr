#ifndef KITSUBASS_H
#define KITSUBASS_H

#include "kitchensink/kitconfig.h"
#include "kitchensink/internal/kitdecoder.h"
#include "kitchensink/internal/subtitle/renderers/kitsubrenderer.h"

KIT_LOCAL Kit_SubtitleRenderer* Kit_CreateASSSubtitleRenderer(Kit_Decoder *dec, int w, int h);

#endif // KITSUBASS_H
