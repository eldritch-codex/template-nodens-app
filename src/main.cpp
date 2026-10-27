import nodens;

class MyApp : public Nodens::Application {
public:
  static inline const Nodens::FApplicationConfig appConfig = {
      .Name = "My Nodens Application",
      .WindowWidth = 1280,
      .WindowHeight = 720,
      .EnableGUI = true,
      .ShouldImGuiBlockInputs = true,
      .Theme = Nodens::ETheme::Dark};

  MyApp() : Application(appConfig) {
    // Add layers here, e.g., PushLayer(new MyLayer());
  }
};

int main() {
  Nodens::InitializeLoggers();
  auto app = MyApp();
  app.Run();

  return 0;
}
