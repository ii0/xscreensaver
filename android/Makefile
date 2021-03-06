# XScreenSaver for Android

export TERM=dumb
GRADLE = ./gradlew

default:: debug
all:: release

clean::
	$(GRADLE) clean

distdepend::

# Set this to the set of platforms you want to compile for in debug mode.
# E.g., if you are running an x86 emulator, there's no point in compiling
# for a dozen other platforms.  Release builds override this to "all".
#
export APP_ABI = all


# TODO:
# check_versions:


# These hacks have interdependencies with others, so we can't build without
# including them or there are link errors:
#
ANDROID_BASE_HACKS=		\
	apple2			\
	bubble3d		\
	pacman			\
	polyhedra		\
	sonar			\
	sproingies		\

# These are the ones that currently work, at least to some degree:
#
export ANDROID_HACKS=		\
	$(ANDROID_BASE_HACKS)	\
	abstractile		\
	anemone			\
	anemotaxis		\
	antmaze			\
	antspotlight		\
	apollonian		\
	atlantis		\
	attraction		\
	atunnel			\
	binaryring		\
	blaster			\
	blinkbox		\
	blitspin		\
	blocktube		\
	boing			\
	bouboule		\
	bouncingcow		\
	boxed			\
	boxfit			\
	braid			\
	bsod			\
	bumps			\
	cage			\
	ccurve			\
	celtic			\
	circuit			\
	cityflow		\
	cloudlife		\
	companioncube		\
	compass			\
	coral			\
	crackberg		\
	crumbler		\
	crystal			\
	cube21			\
	cubenetic		\
	cubestack		\
	cubestorm		\
	cubetwist		\
	cubicgrid		\
	cwaves			\
	cynosure		\
	dangerball		\
	decayscreen		\
	deco			\
	deluxe			\
	demon			\
	discoball		\
	discrete		\
	distort			\
	dnalogo			\
	drift			\
	dymaxionmap		\
	endgame			\
	energystream		\
	engine			\
	epicycle		\
	eruption		\
	esper			\
	euler2d			\
	fadeplot		\
	fiberlamp		\
	filmleader		\
	fireworkx		\
	flame			\
	flipflop		\
	flipscreen3d		\
	flow			\
	fluidballs		\
	flyingtoasters		\
	fuzzyflakes		\
	galaxy			\
	gears			\
	geodesic		\
	geodesicgears		\
	gflux			\
	glblur			\
	glcells			\
	gleidescope		\
	glhanoi			\
	glknots			\
	glmatrix		\
	glplanet		\
	glschool		\
	glslideshow		\
	glsnake			\
	gltext			\
	goop			\
	grav			\
	greynetic		\
	halo			\
	helix			\
	hexadrop		\
	hexstrut		\
	hilbert			\
	hopalong		\
	hypertorus		\
	hypnowheel		\
	ifs			\
	imsmap			\
	interaggregate		\
	interference		\
	intermomentary		\
	jigglypuff		\
	jigsaw			\
	julia			\
	kaleidescope		\
	kaleidocycle		\
	klein			\
	kumppa			\
	lament			\
	lavalite		\
	loop			\
	m6502			\
	maze			\
	maze3d			\
	memscroller		\
	menger			\
	metaballs		\
	mirrorblob		\
	moebius			\
	moebiusgears		\
	moire			\
	moire2			\
	morph3d			\
	mountain		\
	munch			\
	nerverot		\
	noof			\
	noseguy			\
	peepers			\
	penetrate		\
	penrose			\
	petri			\
	piecewise		\
	pinion			\
	pipes			\
	polytopes		\
	pong			\
	popsquares		\
	projectiveplane		\
	providence		\
	pulsar			\
	pyro			\
	quasicrystal		\
	queens			\
	raverhoop		\
	razzledazzle		\
	rd-bomb			\
	ripples			\
	rocks			\
	romanboy		\
	rorschach		\
	rotzoomer		\
	rubik			\
	rubikblocks		\
	sballs			\
	shadebobs		\
	sierpinski		\
	sierpinski3d		\
	skytentacles		\
	slidescreen		\
	slip			\
	spheremonics		\
	splitflap		\
	splodesic		\
	spotlight		\
	squiral			\
	stairs			\
	stonerview		\
	strange			\
	substrate		\
	superquadrics		\
	surfaces		\
	swirl			\
	tangram			\
	tessellimage		\
	thornbird		\
	timetunnel		\
	topblock		\
	triangle		\
	tronbit			\
	truchet			\
	twang			\
	unknownpleasures	\
	vermiculate		\
	vfeedback		\
	vigilance		\
	voronoi			\
	wander			\
	whirlwindwarp		\
	winduprobot		\
	wormhole		\
	xanalogtv		\
	xflame			\
	xjack			\
	xlyap			\
	xmatrix			\
	xrayswarm		\
	xspirograph		\
	zoom			\


# These don't work well enough to turn on by default:
#
ANDROID_TODO=			\
	antinspect		\
	barcode			\
	carousel		\
	fliptext		\
	fontglide		\
	halftone		\
	juggler3d		\
	molecule		\
	pedal			\
	phosphor		\
	photopile		\
	polyominoes		\
	qix			\
	speedmine		\
	starfish		\
	starwars		\
	testx11			\
	unicrud			\


# Download and resize images from jwz.org.
# This saves us having to include 4MB of images in the tar file
# that will only be used by a vast minority of people building
# from source.
# Android actually wants these to be 160x160 but our source is 200x150.

URL = https://www.jwz.org/xscreensaver/screenshots/
WGET = wget -q -U xscreensaver-build-android
CVT  = -thumbnail '150x150^' -gravity center -extent 150x150 \
     \( +clone  -alpha extract \
        -draw 'fill black polygon 0,0 0,15 15,0 fill white circle 15,15 15,0' \
        \( +clone -flip \) -compose Multiply -composite \
        \( +clone -flop \) -compose Multiply -composite \
     \) -alpha off -compose CopyOpacity -composite \
    -colorspace sRGB \
    -strip \
    -quality 95 \
    +dither -colors 128

# If we are making the m6502 hack, create the header file for Android
m6502.h::
	@for h in $(ANDROID_HACKS) ; do \
		if [ $${h} = "m6502" ] ; then \
			echo "Making $${h} header ..."; \
			../hacks/m6502.sh ../hacks/m6502.h ../hacks/images/m6502/*.asm ; \
			echo "Made $${h} header"; \
		fi; \
	done

xscreensaver/res/drawable/%.png:
	@\
	FILE1=`echo "$@" | sed 's!^.*/\([^/]*\)\.png$$!\1.jpg!'` ;	\
	FILE2="$@" ;							\
	FILE1=`echo "$$FILE1" | sed s/rdbomb/rd-bomb/` ;		\
	FILE2=`echo "$$FILE2" | sed s/rd-bomb/rdbomb/` ;		\
	URL="$(URL)$$FILE1" ;						\
	echo "converting $$URL..." ;					\
	rm -f "$$FILE2" ;						\
	$(WGET) -O- "$$URL" |						\
	convert jpg:- $(CVT) "$$FILE2" ;				\
	if [ ! -s "$$FILE2" ]; then					\
	  echo "$$FILE2 failed" >&2 ;					\
	  exit 1 ;							\
	fi

thumbs::
	@for f in $(ANDROID_HACKS) $(ANDROID_TODO) ; do			\
	  $(MAKE) xscreensaver/res/drawable/$$f.png ;			\
	done

clean_thumbs::
	@\
	for f in $(ANDROID_HACKS) $(ANDROID_TODO) ; do			\
	  rm -f xscreensaver/res/drawable/$$f.png ;			\
	done

distclean:: clean_thumbs clean


EXTRA_TARFILES = xscreensaver/res/drawable/thumbnail.png \

echo_tarfiles:
	@FILES=`find . $(EXTRA_TARFILES) \( \(	\
		   -name .DS_Store		\
		-o -name '*~'			\
		-o -name '*.jks'		\
		-o -name '*.keystore'		\
		-o -name '*_dream.xml'		\
		-o -name '*_settings.xml'	\
		-o -name '*_wallpaper.xml'	\
		-o -name AndroidManifest.xml	\
		-o -name strings.xml		\
		-o -name settings.xml		\
		-o -name attrs.xml		\
		-o -name .gitignore		\
		-o -name .gradle		\
		-o -name drawable		\
		-o -name build			\
		-o -name gen			\
		-o -name libs			\
		-o -name obj			\
		\) -prune \)			\
		-o \( \( -type f -o -type l \)	\
		      -print \)			\
		| sed 's@^\./@@' 		\
		| sort` ;			\
	echo $$FILES

images_png_h:
	cd ../hacks/images && $(MAKE)

run_check::
	../hacks/check-configs.pl --build-android $(ANDROID_HACKS)

debug:: m6502.h run_check images_png_h
	$(GRADLE) assembleDebug
release:: m6502.h run_check images_png_h
	export APP_ABI=all ; \
	$(GRADLE) assembleRelease


KEYSTORE = xscreensaver.jks
$(KEYSTORE):
	keytool -genkey -v -keystore $@ \
	-alias xscreensaver -keyalg RSA -keysize 2048 -validity 10000

APK_DIR       = xscreensaver/build/outputs/apk/release/
APK_UNSIGNED  = $(APK_DIR)xscreensaver-release-unsigned.apk
APK_UNALIGNED = $(APK_DIR)xscreensaver-release-unaligned.apk
APK_SIGNED    = $(APK_DIR)xscreensaver-release.apk

  TOOLDIR = $(shell ls -d $$HOME/Library/Android/sdk/build-tools/* | tail -1)
 ZIPALIGN = $(TOOLDIR)/zipalign
JARSIGNER = jarsigner

sign_release::
	cp -p $(APK_UNSIGNED) $(APK_UNALIGNED)
	$(JARSIGNER) -verbose -sigalg SHA1withRSA -digestalg SHA1 \
		     -keystore $(KEYSTORE) $(APK_UNALIGNED) xscreensaver
	rm -f $(APK_SIGNED)
	$(ZIPALIGN) -v 4 $(APK_UNALIGNED) $(APK_SIGNED)
	rm -f $(APK_UNALIGNED)
	$(JARSIGNER) -verify -verbose -certs $(APK_SIGNED)
	@ls -lF $(APK_SIGNED)

apk:: release
	@\
  VERS=`sed -n 's/[^0-9]*\([0-9]\.[0-9][^. ]*\).*/\1/p' ../utils/version.h` ; \
  HEAD="xscreensaver-$$VERS" ;						      \
  if [ ! -s $(APK_SIGNED) -o $(APK_UNSIGNED) -nt $(APK_SIGNED) ]; then	\
    $(MAKE) sign_release ;						\
  fi ;									\
  set -x ;								\
  cp -p $(APK_SIGNED) ../archive/$$HEAD.apk


## #### Pare it down for faster debugging...
#export APP_ABI = armeabi-v7a
#export APP_ABI = x86
#
#export ANDROID_HACKS=		\
#	$(ANDROID_BASE_HACKS)	\
#  bsod				\
#  apollonian			\
#  engine			\
#  dnalogo			\
#  twang			\
#  memscroller			\
#  phosphor			\
#  discoball			\
#  cubetwist			\
#  cubestack			\
#  splodesic			\
