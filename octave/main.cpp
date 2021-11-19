

//https://octave.org/doc/v6.3.0/Standalone-Programs.html

#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/interpreter.h>
#include <octave-5.2.0/octave/octave-default-image.h>

int main(void)
{
  // Create interpreter.

  octave::interpreter interpreter;

  try
  {
    int status = interpreter.execute();

    if (status != 0)
    {
      std::cerr << "creating embedded Octave interpreter failed!"
                << std::endl;
      return status;
    }

    //Lista de argumentos para o comando pkg
    octave_value_list load_p;
    load_p(0) = octave_value("load"); //Argumento load
    load_p(1) = octave_value("image"); //Argumento image(Pacote)

    octave::feval("pkg", load_p); //Chama o comando pkg com a lista de argumentos
  
    //Cria um lista de valores
    octave_value_list in;
    in(0) = octave_value("rice.jpg"); //Adiciona na lista de argumentos o nome da imagem na posição 1 da lista

    //Cria outra lista de saida
    octave_value_list out;
    out(0) = octave_value(octave::feval("imread", in(0), 1)); //Executa o comando imread com o a lista de argumentos

    //Cria outra lista de valores
    octave_value_list in2;

    //Cria a lista de argumentos para salvar a imagem
    in2(1) = octave_value("image");
    in2(2) = octave_value("png");

    //Cria uma nova lista
    octave_value_list in3;
    in3(0) = octave_value(out(0));
    out(3) = octave_value(octave::feval("imhist", in3)); //Executa o comando imadjust com a lista de argumentos
    in2(0) = octave_value(out(3));

    octave::feval("imwrite", in2, 2);//Salva a imagem com a lista de argumentos n2

    if (out.length() > 0)
      std::cout << "OK" << std::endl;
    else
      std::cout << "invalid\n";
  }
  catch (const octave::exit_exception &ex)
  {
    std::cerr << "Octave interpreter exited with status = "
              << ex.exit_status() << std::endl;
  }
  catch (const octave::execution_exception &)
  {
    std::cerr << "error encountered in Octave evaluator!" << std::endl;
  }

  return 0;
}
