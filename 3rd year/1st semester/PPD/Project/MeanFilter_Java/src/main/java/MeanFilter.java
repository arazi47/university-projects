import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class MeanFilter {
    private int width;
    private int height;
    private int[][] imageArray;
    private int[][] output;

    public MeanFilter(String imagePath) {
        try {
            BufferedImage image = ImageIO.read(new File((imagePath)));
            this.height = image.getHeight();
            this.width = image.getWidth();
            this.imageArray = new int[this.height][this.width];
            for (int i = 0; i < this.height; ++i) {
                for (int j = 0; j < this.width; ++j) {
                    this.imageArray[i][j] = image.getRGB(j, i);
                }
            }

            this.output = new int[this.height][this.width];
            ExecutorService service = Executors.newFixedThreadPool(4);

            for (int v=1; v<height; v++) {
                for (int u=1; u<width; u++) {
                    // u and v should be final if used in a lambda expression
                    int finalU = u;
                    int finalV = v;
                    service.execute(() -> {
                        //compute filter result for position (u,v)
                        int sumr = 0, sumg = 0, sumb = 0;
                        for (int j=-1; j<=1; j++) {
                            for (int i=-1; i<=1; i++) {
                                if(finalU + j < width && finalV + i < height){
                                    int pixel = imageArray[finalV+i][finalU+j];
                                    int rr = (pixel&0x00FF0000)>>16;
                                    int rg = (pixel&0x0000FF00)>>8;
                                    int rb = pixel&0x000000FF;
                                    sumr+=rr;
                                    sumg+=rg;
                                    sumb+=rb;
                                }
                            }
                        }

                        // 3x3 kernel, value for each cell is 1/9
                        sumr /= 9;
                        sumg /= 9;
                        sumb /= 9;
                        int newPixel = 0xFF000000 | (sumr << 16) | (sumg << 8) | sumb;
                        output[finalV][finalU] = newPixel;
                    });
                }
            }

            service.shutdown();
            service.awaitTermination(10, TimeUnit.SECONDS);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void writeToFile() throws IOException {
        // Create the filtered image from the output array
        BufferedImage filteredImage = new BufferedImage(this.width, this.height, BufferedImage.TYPE_INT_RGB);
        for(int j = 0; j < height; ++j){
            for(int i = 0; i < width; ++i){
                filteredImage.setRGB(i, j, output[j][i]);
            }
        }

        File filteredImageFile = new File("output.jpg");
        ImageIO.write(filteredImage, "jpg", filteredImageFile);
    }
}
