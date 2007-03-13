/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __otbFrostImageFilter_h
#define __otbFrostImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkNumericTraits.h"

namespace otb
{

/** \class FrostImageFilter
 * \brief Anti-speckle image filter
 *
 * Uses a negative exponential convolution kernel.
 * The output of the filter for pixel p is:
 *      \f$ \hat I_{s}=\sum_{p\in\eta_{p}} m_{p}I_{p} \f$ 
 *
 * where :   \f$ m_{p}=\frac{KC_{s}^{2}\exp(-KC_{s}^{2}d_{s,p})}{\sum_{p\in\eta_{p}} KC_{s}^{2}\exp(-KC_{s}^{2}d_{s,p})} \f$
 *    and  \f$ d_{s,p}=\sqrt{(i-i_{p})^2+(j-j_{p})^2} \f$
 *
 * \f$ K \f$     : the decrease coefficient
 * \f$ (i,j)\f$ : the coordinates of the pixel inside the region
 * defined by \f$ \eta_{s} \f$ 
 * \f$ (i_{p},j_{p})\f$ : the coordinates of the pixels belonging to \f$ \eta_{p} \subset \eta_{s} \f$
 * \f$ C_{s}\f$ : the variation coefficient computed over \f$ \eta_{p}\f$ 
 * 
 */

template <class TInputImage, class TOutputImage>
class ITK_EXPORT FrostImageFilter :  public itk::ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** 	Extrait les dimensions aussi bien des images 
  	d'entrée (Input) que de sortie (Output). */
  itkStaticConstMacro(		InputImageDimension,
  				unsigned int,
                      		TInputImage::ImageDimension);
  itkStaticConstMacro(		OutputImageDimension, 
  				unsigned int,
                      		TOutputImage::ImageDimension);

  /** "typedef" pour simplifier la définition et la déclaration de variables. */
  typedef TInputImage InputImageType;
  /** "typedef" pour simplifier la définition et la déclaration de variables. */
  typedef TOutputImage OutputImageType;

  /** "typedef" pour les classes standards. */
  typedef FrostImageFilter Self;
  typedef itk::ImageToImageFilter< InputImageType, OutputImageType> Superclass;
  typedef itk::SmartPointer<Self> Pointer;
  typedef itk::SmartPointer<const Self>  ConstPointer;

  /** Methode pour la gestion "object factory". */
  itkNewMacro(Self);

  /** Retourne le nom de la classe. */
  itkTypeMacro(FrostImageFilter, ImageToImageFilter);
  
  /** Définition des images supportées. */
  typedef typename InputImageType::PixelType InputPixelType;
  typedef typename OutputImageType::PixelType OutputPixelType;
  /** "typedef" définissant un réel dans cette classe. */
  typedef typename itk::NumericTraits<InputPixelType>::RealType InputRealType;
  
  typedef typename InputImageType::RegionType InputImageRegionType;
  typedef typename OutputImageType::RegionType OutputImageRegionType;

  /** "typedef" définissant la taille d'une image. */
  typedef typename InputImageType::SizeType SizeType;

  /** Positionne le rayon définissant le voisinage utilisé pour le calcul du filtre. */
  itkSetMacro(Radius, SizeType);

  /** Récupère le rayon définissant le voisinage utilisé pour le calcul du filtre. */
  itkGetConstReferenceMacro(Radius, SizeType);
  
  /** Positionne le nombre de vues utilisé pour le calcul du filtre. */
  itkSetMacro(Deramp, double);
  /** Récupère le nombre de vues (référencé constant) utilisé pour le calcul du filtre. */
  itkGetConstReferenceMacro(Deramp, double);

  /** FrostImageFilter a besoin d'une zone de traitement plus large en entrée qu'en sortie 
   * afin de permettre une utilisation du filtre par la méthode dite pipeline
   *
   * \sa ImageToImageFilter::GenerateInputRequestedRegion() */
  virtual void GenerateInputRequestedRegion() throw(itk::InvalidRequestedRegionError);

protected:
  FrostImageFilter();
  virtual ~FrostImageFilter() {};
  void PrintSelf(std::ostream& os, itk::Indent indent) const;

  /** FrostImageFilter peut etre implémentée pour un traitement de filtre multithreaded.
   * Ainsi, cette implémentation fournit la méthode ThreadedGenerateData()
   * qui est appelée pour chaque thread du process. Les données image sont allouées automatiquement 
   * par la classe "mère" en appelant la méthode ThreadedGenerateData(). ThreadedGenerateData peut seulement 
   * écrire la portion de l'image spécifiée par le paramètre "outputRegionForThread"
   *
   * \sa ImageToImageFilter::ThreadedGenerateData(),
   *     ImageToImageFilter::GenerateData() */
  void ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,
                            int threadId );

private:
  FrostImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  /** Déclaration du rayon */
  SizeType m_Radius;
  /** Déclaration du facteur de décroissance du filtre */
  double m_Deramp;
};
} // end namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbFrostImageFilter.txx"
#endif

  
#endif
