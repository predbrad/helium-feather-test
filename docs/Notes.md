# I haven't used that specific Adafruit Feather board, but the whole Feather line is pretty awesome. Feather boards have increasingly been my go-to platform for any project that is too much for an Arduino Nano (for ~$3 via Amazon Prime, Nanos are still the first board I turn to by default). Some tips...
## The SAMD21 family of chips are 2nd only to ATmega32 chips in terms of library compatibility. That is to say, most libraries that are "Arduino compatible" out there are also SAMD21 compatible, but not all of them (yet). If you're planning on using a particular library from the wider web, just make sure it states that it is SAMD21 compatible. In 5 years or so, I expect the SAMD21 line to be the successor to the ATmega32 line, but we're still in the transition phase.

## I have a general Template project on GitHub that I use as a starting point for my FW projects. It's not suuuper clean (since I'm the only user right now), but it includes the code structure and libraries that are the basis for most of my projects. I sent you an invite in case you want to use any of that.

## You get rechargeable battery capabilities "for free" with a Feather Board - just pick the size LiPo battery you want to use for your project and plug it in the battery connector. 

## There are a few less GPIO pins on the Feather boards than the Nanos. This won't be an issue for a basic sensor device, but just something to keep in mind when imagining moving from Arduino Unos or Nanos to a Feather.

## Arduinos operate at 5V, which are generally compatible with 3.3V systems by default. Feathers operate at 3.3V, so if you use external sensors that are intended for 5V systems, you may have to make some additional accommodations for it. If you use 3.3V sensors, you're good.
