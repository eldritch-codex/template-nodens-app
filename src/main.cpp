import nodens;

class MyApp : public Nodens::Application {
public:
  static inline const Nodens::FApplicationSpecification appSpecifications = {
      .Name = "My Nodens Application",
      .WindowWidth = 1280,
      .WindowHeight = 720,
      .EnableGUI = true,
      .ShouldImGuiBlockInputs = true,
      .DefaultTheme = Nodens::EDefaultTheme::Dark};

  MyApp() : Application(appSpecifications) {
    // Add layers here, e.g., PushLayer(new MyLayer());
  }
};

int main() {
  Nodens::InitializeLoggers();
  auto app = MyApp();
  app.Run();

  return 0;
}
