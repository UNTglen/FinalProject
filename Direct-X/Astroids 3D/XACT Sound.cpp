#include "XACT Sound.h"

stXACTAudio g_xactSound;
IXACT3Engine *g_soundEngine = NULL;

bool SetupXACT(char *waveBank, char *soundBank)
{
   ZeroMemory(&g_xactSound, sizeof(stXACTAudio));

   if(FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED)))
      return false;

   if(FAILED(XACT3CreateEngine(0,
      &g_soundEngine)))
      return false;

   if(g_soundEngine == NULL)
      return false;

   XACT_RUNTIME_PARAMETERS xparams = {0};
   xparams.lookAheadTime=250;

   if(FAILED(g_soundEngine->Initialize(&xparams)))
      return false;

   if(!LoadWaveBank(waveBank))
      return false;

   if(!LoadSoundBank(soundBank))
      return false;

   return true;
}

bool LoadWaveBank(char *fileName)
{
   HANDLE file = CreateFile(fileName, GENERIC_READ,
                            FILE_SHARE_READ, NULL,
                            OPEN_EXISTING, 0, NULL);

  if(file == INVALID_HANDLE_VALUE)
     return false;
  DWORD fileSize = GetFileSize(file, NULL);

  if(fileSize == -1)
  {
     CloseHandle(file);
     return false;
  }
  HANDLE mapFile = CreateFileMapping(file, NULL, PAGE_READONLY,
                                     0, fileSize, NULL);

  if(!mapFile)
  {
     CloseHandle(file);
     return false;
  }

  void *ptr = MapViewOfFile(mapFile, FILE_MAP_READ, 0, 0, 0);

  if(!ptr)
  {
     CloseHandle(mapFile);
     CloseHandle(file);
     return false;
  }

  g_xactSound.m_waveBankData = ptr;

  if(FAILED(g_soundEngine->CreateInMemoryWaveBank(
     g_xactSound.m_waveBankData,
     fileSize, 0, 0, &g_xactSound.m_waveBank)))
  {
     CloseHandle(mapFile);
     CloseHandle(file);
     return false;
  }

  CloseHandle(mapFile);
  CloseHandle(file);

  return true;
}


bool LoadSoundBank(char *fileName)
{
	HANDLE file = CreateFile(fileName, GENERIC_READ,
                            FILE_SHARE_READ, NULL,
                            OPEN_EXISTING, 0, NULL);

  if(file == INVALID_HANDLE_VALUE)
     return false;
  DWORD fileSize = GetFileSize(file, NULL);

  if(fileSize == -1)
  {
     CloseHandle(file);
     return false;
  }
   g_xactSound.m_soundBankData=new BYTE[fileSize];
   ESASSERT(&g_xactSound.m_soundBankData);

   DWORD bytesRead;
   if(ReadFile(file,g_xactSound.m_soundBankData,fileSize,&bytesRead,NULL)!=0)
   {
	   g_soundEngine->CreateSoundBank(g_xactSound.m_soundBankData,fileSize,0,0,&g_xactSound.m_soundBank);
   }

   CloseHandle(file);
   return true;
}

void CloseAll()
{
	if (g_soundEngine)
{
   g_soundEngine->ShutDown();
   g_soundEngine->Release();
}
	if(g_xactSound.m_soundBankData)
	delete []g_xactSound.m_soundBankData;

if (g_xactSound.m_waveBankData)
   UnmapViewOfFile(g_xactSound.m_waveBankData);

CoUninitialize();

}