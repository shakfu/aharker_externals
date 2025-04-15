# run this when linker-flags are out of sync
# see: https://cycling74.com/forums/missing-jdataview-methods-in-max-sdk-820?replyPage=1#reply-67fdbe503bd53f00135c8827
perl -pe "s/(-Wl,-U,_\S+)/'\$1'/g" \
	source/max-sdk-base/c74support/max-includes/c74_linker_flags.txt > \
	source/max-sdk-base/script/max-linker-flags.txt
