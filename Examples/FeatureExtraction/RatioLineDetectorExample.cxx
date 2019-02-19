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



/* Example usage:
./RatioLineDetectorExample Input/amst2.png Output/amstLineRatios.png Output/amstLineRatioDirections.png 5 1
*/


// This example illustrates the use of the \doxygen{otb}{RatioLineDetectorImageFilter}.
// This filter is used for line detection in SAR images. Its principle
// is described in \cite{tup-98}: a line is detected if two parallel
// edges are present in the images. These edges are detected with the
// ratio of means detector.
//
// The first step required to use this filter is to include its header file.

#include "otbLineRatioDetectorImageFilter.h"

#include "otbImage.h"
#include "otbImageFileReader.h"
#include "itkUnaryFunctorImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "otbImageFileWriter.h"

int main(int argc, char * argv[])
{

  if (argc != 6)
    {
    std::cerr << "Usage: " << argv[0] << " inputImageFile ";
    std::cerr <<
    " outputEdgesImageFile outputDirectionsImageFile length width" << std::endl;
    return EXIT_FAILURE;
    }

  //  Then we must decide what pixel type to use for the image. We
  //  choose to make all computations with floating point precision
  //  and rescale the results between 0 and 255 in order to export PNG images.

  typedef  float         InternalPixelType;
  typedef  unsigned char OutputPixelType;

  //  The images are defined using the pixel type and the dimension.

  typedef otb::Image<InternalPixelType,  2> InternalImageType;
  typedef otb::Image<OutputPixelType,  2>   OutputImageType;

  //  The filter can be instantiated using the image types defined above.

  typedef otb::LineRatioDetectorImageFilter
  <InternalImageType, InternalImageType>  FilterType;

  //  An \doxygen{otb}{ImageFileReader} class is also instantiated in order to read
  //  image data from a file.

  typedef otb::ImageFileReader<InternalImageType> ReaderType;

  // An \doxygen{otb}{ImageFileWriter} is instantiated in order to write the
  // output image to a file.

  typedef otb::ImageFileWriter<OutputImageType> WriterType;

  // The intensity rescaling of the results will be carried out by the
  // \code{itk::RescaleIntensityImageFilter} which is templated by the
  // input and output image types.

  typedef itk::RescaleIntensityImageFilter<InternalImageType,
      OutputImageType> RescalerType;

  //  Both the filter and the reader are created by invoking their \code{New()}
  //  methods and assigning the result to SmartPointers.

  ReaderType::Pointer reader = ReaderType::New();
  FilterType::Pointer filter = FilterType::New();

  //  The same is done for the rescaler and the writer.

  RescalerType::Pointer rescaler = RescalerType::New();
  WriterType::Pointer   writer = WriterType::New();

  reader->SetFileName(argv[1]);

  //  The \code{itk::RescaleIntensityImageFilter} needs to know which
  //  is the minimu and maximum values of the output generated
  //  image. Those can be chosen in a generic way by using the
  //  \code{NumericTraits} functions, since they are templated over
  //  the pixel type.

  rescaler->SetOutputMinimum(itk::NumericTraits<OutputPixelType>::min());
  rescaler->SetOutputMaximum(itk::NumericTraits<OutputPixelType>::max());

  //  The image obtained with the reader is passed as input to the
  //  \doxygen{otb}{LineRatioDetectorImageFilter}. The pipeline is built as follows.
  //
  //  \index{otb::LineRatioDetectorImageFilter!SetInput()}

  filter->SetInput(reader->GetOutput());
  rescaler->SetInput(filter->GetOutput());
  writer->SetInput(rescaler->GetOutput());

  //  The methods \code{SetLengthLine()} and \code{SetWidthLine()}
  //  allow setting the minimum length and the typical witdh of the
  //  lines which are to be detected.
  //
  //  \index{otb::LineRatioDetector!SetWidthLine()}
  //  \index{otb::LineRatioDetector!SetLengthLine()}

  filter->SetLengthLine(atoi(argv[4]));
  filter->SetWidthLine(atoi(argv[5]));

  //  The filter is executed by invoking the \code{Update()} method. If the
  //  filter is part of a larger image processing pipeline, calling
  //  \code{Update()} on a downstream filter will also trigger update of this
  //  filter.

  filter->Update();

  writer->SetFileName(argv[2]);
  writer->Update();

  // We can also obtain the direction of the lines by invoking the
  // \code{GetOutputDirection()} method.

  writer->SetFileName(argv[3]);
  rescaler->SetInput(filter->GetOutputDirection());
  writer->SetInput(rescaler->GetOutput());
  writer->Update();

  //  Software Guide : BeginLatex Figure~\ref{fig:LINERATIO_FILTER}
  // shows the result of applying the LineRatio edge detector filter
  // to a SAR image.  \begin{figure} \center
  // \includegraphics[width=0.25\textwidth]{amst.eps}
  // \includegraphics[width=0.25\textwidth]{amstLineRatios.eps}
  // \includegraphics[width=0.25\textwidth]{amstLineRatioDirections.eps}
  // \itkcaption[Line Ratio Detector Application]{Result of applying
  // the \doxygen{otb}{LineRatioDetectorImageFilter} to a SAR
  // image. From left to right : original image, line intensity and
  // edge orientation.}  \label{fig:LINERATIO_FILTER} \end{figure}
  //
  //  \relatedClasses
  //  \begin{itemize}
  //  \item \doxygen{otb}{LineCorrelationDetectorImageFilter}
  //  \end{itemize}

  return EXIT_SUCCESS;
}
