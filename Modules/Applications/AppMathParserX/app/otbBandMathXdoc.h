/*
 * Copyright (C) 2005-2019 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

SetDocLongDescription(
      "This application performs a mathematical operation on several multi-band "
      "images and outputs the result into an image (multi- or mono-band, as "
      "opposed to the BandMath OTB-application). The mathematical formula is "
      "done by the muParserX library.\n\n"

      "The list of features and the syntax of muParserX is available at [1].\n\n"

      "As opposed to muParser (and thus the BandMath OTB-application [2]), "
      "muParserX supports vector expressions which allows outputting multi-band "
      "images.\n\n"

      "Hereafter is a brief reference of the muParserX syntax\n\n"

      "Fundamentals\n"
      "------------\n\n"

      "The formula can be written using:\n\n"
      "* numerical values ( 2.3, -5, 3.1e4, ...)\n"
      "* variables containing pixel values (please, note the indexing of "
      "inputs from 1 to N). Examples for the first input image:\n\n"
      "  * ``im1`` a pixel from 1st input, made of n components (n bands)\n"
      "  * ``im1b2`` the 2nd component of a pixel from 1st input (band index is 1-based)\n"
      "  * ``im1b2N3x4`` a 3x4 pixels Neighbourhood of a pixel the 2nd component of a pixel from the 1st input\n"
      "  * ``im1PhyX`` horizontal (X-axis) spacing of the 1st input.\n"
      "  * ``im1PhyY`` vertical (Y-axis) spacing of the 1st input input.\n"
      "  * ``im1b2Mean`` mean of the 2nd component of the 1st input (global statistics)\n"
      "  * ``im1b2Mini`` minimum of the 2nd component of the 1st input (global statistics)\n"
      "  * ``im1b2Maxi`` maximum of the 2nd component of the 1st input (global statistics)\n"
      "  * ``im1b2Sum`` sum of the 2nd component of the 1st input (global statistics)\n"
      "  * ``im1b2Var`` variance of the 2nd component of the 1st input (global statistics)\n"
      "  * ``idxX`` and ``idxY`` are the indices of the current pixel (generic variables)\n"
      "* binary operators:\n\n"
      "  * ``+`` addition, ``-`` subtraction, ``*`` multiplication, ``/`` division\n"
      "  * ``^`` raise x to the power of y\n"
      "  * ``<`` less than, ``>`` greater than, ``<=`` less or equal, ``>=`` greater or equal\n"
      "  * ``==`` equal, ``!=`` not equal\n"
      "  * logical operators: ``or``, ``and``, ``xor``\n"
      "  * bit manipulation: ``&`` (and), ``|`` (or), ``<<``(left shift) and ``>>`` (right shift)"
      "* if-then-else operator: ``(condition ? value_true : value_false)``\n"
      "* functions: abs(), exp(), log(), sin(), cos(), min(), max(), ...\n\n"

      "Always keep in mind that this application only addresses mathematically "
      "well-defined formulas. For instance, it is not possible to add vectors of"
      " different dimensions (e.g. addition of a row vector with a column vector"
      "), or a scalar to a vector or matrix, or divide two vectors, etc.\n\n"

      "Thus, it is important to remember that a pixel of n components is always "
      "represented as a row vector.\n\n"

      "Example:\n"
      "  ``im1 + im2``\n"
      "  represents the addition of pixels from the 1st and 2nd inputs. This "
      "expression is consistent only if both inputs have the same number of "
      "bands.\n\n"

      "Please note that it is also possible to use the following expressions"
      " to obtain the same result:\n\n"
      "  * ``im1b1 + im2b1``\n"
      "  * ``im1b2 + im2b2``\n"
      "  * ...\n\n"

      "Nevertheless, the first expression is by far much pleaseant. We call "
      "this new functionality the 'batch mode' (performing the same operation "
      "in a band-to-band fashion).\n\n"

      "Operations involving bit manipulation\n"
      "--------------------------------------------\n\n"
      "In order to manipulate bit, one need to convert its data into integer. "
      "To do so, muParserX has a type conversions operator: (int). Prefixing "
      "your images with it will allow you to perform such operations.\n\n"

      "Example:\n"
      " *``(int)im1b1 & 0b00000001`` (bitwise and)"
      " *``(int)im1b1 >> 1`` (right shift operator)"


      "Operations involving neighborhoods of pixels\n"
      "--------------------------------------------\n\n"

      "Another new feature is the possibility to perform operations that "
      "involve neighborhoods of pixels. Variables related to such neighborhoods "
      "are always defined following the ``imIbJNKxP`` pattern, where:\n\n"
      "  - ``I`` is an number identifying the image input (remember, input #0 = im1, "
      "and so on)\n"
      "  - ``J`` is an number identifying the band (remember, first band is indexed by 1)\n"
      "  - ``KxP`` are two numbers that represent the size of the neighborhood (first "
      "one is related to the horizontal direction)\n\n"

      "NB: All neighborhood are centered, thus ``K`` and ``P`` must be odd numbers.\n\n"

      "Many operators come with this new functionality:\n\n"
      "  - dotpr\n"
      "  - mean\n"
      "  - var\n"
      "  - median\n"
      "  - vmin\n"
      "  - vmax\n"
      "  - etc.\n\n"

      "For instance, if ``im1`` represents the pixel of a 3 bands image::\n\n"
      "  im1 - mean( im1b1N5x5, im1b2N5x5, im1b3N5x5 )\n\n"
      "could represent a high pass filter (note that by implying three "
      "neighborhoods, the operator mean returns a row vector of three components"
      ". It is a typical behaviour for many operators of this application).\n\n"

      "In addition to the previous operators, other operators are available:\n\n"
      "  - existing operators/functions from muParserX, that were not originally "
      "defined for vectors and matrices (e.g. cos, sin). These new "
      "operators/functions keep the original names to which we added the prefix "
      "``v`` for vector (``vcos``, ``vsin``, etc.)\n"
      "  - ``mult``, ``div`` and ``pow`` operators, that perform element-wise multiplication, "
      "division or exponentiation of vector/matrices (e.g. ``im1 div im2``).\n"
      "  - ``mlt``, ``dv`` and ``pw`` operators, that perform multiplication, division or "
      "exponentiation of vector/matrices by a scalar (e.g. ``im1 dv 2.0``).\n"
      "  - ``bands``, which is a very useful operator. It allows selecting specific "
      "bands from an image, or to rearrange them in a new vector (e.g."
      "``bands( im1, { 1, 2, 1, 1 } )`` produces a vector of 4 components made of "
      "band 1, band 2, band 1 and band 1 values from the first input.\n\n"
      "Note that curly brackets must be used in order to select the desired band"
      "indices.\n\n"

      "The application itself\n"
      "----------------------\n\n"

      "The application can use an expression supplied with the ``-exp`` parameter."
      " It can also use an input context file, that defines variables and "
      "expressions. An example of context file is given below::\n\n"
      "  #F expo 1.1\n"
      "  #M kernel1 { 0.1 , 0.2 , 0.3; 0.4 , 0.5 , 0.6; 0.7 , 0.8 , 0.9; 1 , 1.1"
      ", 1.2; 1.3 , 1.4 , 1.5 }\n"
      "  #E $dotpr( kernel1, im1b1N3x5 ); im2b1^expo$\n\n"

      "As we can see, #I/#F allows the definition of an integer/float constant, "
      "whereas #M allows the definition of a vector/matrix. In the latter case, "
      "elements of a row must be separated by commas, and rows must be separated"
      " by semicolons. It is also possible to define expressions within the same"
      " txt file, with #E <expr> (see limitations, below)."
    );