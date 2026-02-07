Load "allegro.rh"
if iswindows()
	LoadLib("ring_allegro_threads.dll")
but ismacosx()
	LoadLib("libringallegro.dylib")
else
	LoadLib("libringallegro.so")
ok