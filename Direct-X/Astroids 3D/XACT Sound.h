#ifndef _XACT_H
#define _XACT_H

#include <xact3.h>
#include <assert.h>


struct stXACTAudio
{
   IXACT3WaveBank* m_waveBank;
   IXACT3SoundBank* m_soundBank;
   void *m_waveBankData;
   void *m_soundBankData;
};

extern stXACTAudio g_xactSound;
extern IXACT3Engine *g_soundEngine;

extern bool SetupXACT(char *waveBank, char *soundBank);
extern bool LoadWaveBank(char *fileName);
extern bool LoadSoundBank(char *fileName);
extern void CloseAll();

#ifndef ESASSERT
    #if !defined(_DEBUG) && !defined(NDEBUG)
        #define NDEBUG
    #endif
    #include <assert.h>
    #define ESASSERT(x)    assert(x)
#endif //ES_ASSERT

#endif